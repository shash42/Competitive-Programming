typedef unsigned long long ull;
const int MOD=1e9+7, N=5e3+3, hmod=2147483647;
int rng(const int before, const int after) { // Generate random base in (before, after] 
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); 
    std::mt19937 mt_rand(seed ^ ull(new ull)); //remove ^ ull thing for speed
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base; //use steady_clock() for speed, for 64 bit mt19937_64 and lint
}
lint _add(lint x, lint y, lint mod = MOD)
{
	x%=mod; y%=mod;
    lint ret=x+y;
    ret%=mod;
    if(ret < 0) ret+=mod;
    return ret;
}
lint _mult(lint x, lint y, lint mod = MOD)
{
    x%=mod; y%=mod;
    lint ret=x*y;
    ret%=mod;
    if(ret < 0) ret+=mod;
    return ret;
}
vector<int> pow1;
vector<ull> pow2; //powers of MOD and 2^64
int base, mxlen;
void InitHash(int before, int after, int len)
{
	mxlen = len;
	base = rng(before, after);
	base+=(base%2==0);
	pow1.push_back(1);
	pow2.push_back((ull) 1);
	while(pow1.size()<=mxlen)
	{
		pow1.push_back(_mult(pow1.back(), base, hmod));
		pow2.push_back(pow2.back()*base);
	}
}
struct PolyHash //call PolyHash::Init with range (before, after, maxlength) first. //Keep prefix 
{
	vector<int> pref1; //NOTE: for strings always keep before > 256
	vector<ull> pref2; // (not 29 for eg) because ASCII is used

	PolyHash(string &s)
	{
		pref1.resize(s.length()+1);
		pref2.resize(s.length()+1);
		for(int i = 0; i < s.length(); i++)
		{
			pref1[i+1]=_add(pref1[i], _mult( (int) s[i], pow1[i], hmod), hmod); 
			pref2[i+1]=pref2[i] + ((int) s[i])*pow2[i]; 
		}
	}
	PolyHash(int a[], int asz)
	{
		pref1.resize(asz+1);
		pref2.resize(asz+1);
		for(int i = 0; i < asz; i++)
		{
			pref1[i+1]=_add(pref1[i], _mult(a[i], pow1[i], hmod), hmod); 
			pref2[i+1]=pref2[i] + a[i]*pow2[i]; 
		}
	}	
	pii RangeHash(int l, int r) //returns hash from [l, r] inclusive
	{
		int tmplen = r-l+1;
		int hash1 = _add(pref1[r+1], -pref1[l], hmod);
        ull hash2 = pref2[r+1] - pref2[l];
        if (mxlen != 0)
        {
            hash1 = _mult(hash1, pow1[mxlen-(l+tmplen-1)], hmod);
            hash2 *= pow2[mxlen-(l+tmplen-1)];
        }
		return make_pair(hash1, hash2);
	}
};
string s;
signed main()
{
	InitHash(257, 1e9+7, N);
	PolyHash hash_s(s);
	cout << hash_s.RangeHash(l, r).F << endl;
}