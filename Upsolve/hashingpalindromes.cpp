#include<bits/stdc++.h>
//#define int long long
#define lint long long
#define pii pair<int, int>
#define F first
#define S second

typedef unsigned long long ull;

using namespace std;

const int MOD=1e9+7, N=5e3+3, hmod=2147483647;

// Generate random base in (before, after) open interval: NOTE: for strings always keep before > 256 (not 29 for eg) because ASCII is used
int rng(const int before, const int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed ^ ull(new ull));
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base;
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
	vector<int> pref1;
	vector<ull> pref2;

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
			pref2[i+1]=_add(pref2[i], _mult(a[i], pow2[i], hmod), hmod); 
		}
	}	

	pii RangeHash(int l, int r)
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


	
string s, t;
int q, slen, dp[N][N];
bool ispal[N][N];
signed main()
{
	cin >> s;
	slen=s.length();
	InitHash(257, 1e9+7, N);
	for(int i = 0; i < slen; i++)
	{
		t+=s[slen-i-1];
	}
	PolyHash hash_s(s);
	PolyHash hash_t(t);
	for(int i = 0; i < s.length(); i++)
	{
		for(int j = 0; i+j<s.length() && j <=i; j++)
		{
			if(hash_s.RangeHash(i-j, i-1)==hash_t.RangeHash(slen-(i+j)-1, slen-(i+1)-1)) ispal[i-j][i+j]=true;
			if(i+j+1<s.length() && hash_s.RangeHash(i-j, i)==hash_t.RangeHash(slen-(i+j+1)-1, slen-(i+1)-1)) ispal[i-j][i+j+1]=true;
		}
	}
	/*for(int i = 0; i < s.length(); i++)
	{
		for(int j = 0; j < s.length(); j++)
		{
			cout << i << " " << j << " ";
			cout << (ispal[i][j]==true) << endl;
		}
	}*/
 	for(int i = 0; i < s.length(); i++)
	{
		dp[i][i]=1;
		if(i+1!=s.length()) dp[i][i+1]=(ispal[i][i+1]==true)+2;
	}
	for(int len = 3; len <= s.length(); len++)
	{
		for(int i = 0; i <= s.length()-len; i++)
		{
			dp[i][i+len-1]=dp[i+1][i+len-1] + dp[i][i+len-2] - dp[i+1][i+len-2] + (ispal[i][i+len-1]==true);
		}
	}
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		l--; r--;
		printf("%d\n", dp[l][r]);
	}
}