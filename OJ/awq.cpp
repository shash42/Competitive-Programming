#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 1e5 + 5, MOD=1e9+7, A = 2, B = 30;

string binstr(int x)
{
    string ret = "";
    for(int i = B; i > 0; i--)
    {
        int c = (1<<i);
        ret += ('0' + (x%c >= c/2));
    }
    return ret;
}
inline int modpow(lint base, int exp, int modulo) {
    base %= modulo;
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulo;
        base = (base * base) % modulo;
        exp >>= 1;
    }
    return result;
}
struct node //Set A to alphabet size and change base character from '0' to 'a' if required.
{
    bool isend = false;
    char ch;
    node *child[A];
    node *par = nullptr;
    int cnt = 0, lfcnt = 0; //cnt is sheer count, lfcnt is no. of distinct entries.
    node(node *parr, char chh)
    {
        ch = chh;
        par = parr;
        for(int i = 0; i < A; i++)
        {
            child[i] = nullptr;
        }
    }
} *root;
void trinsert(string &ss)
{
    node *curr = root;
    (curr->cnt)++; //root
    for(int i = 0; i < ss.length(); i++)
    {
        if(curr->child[ss[i] - '0'] == nullptr)
        {
            curr->child[ss[i] - '0'] = new node(curr, ss[i]);
        }
        curr = curr->child[ss[i] - '0'];
        (curr->cnt)++;
    }
    if(!(curr->isend)) //is a new distinct entry
    {
        curr->isend = true;
        while(curr->par) //if distinct count has to be maintained
        {
            (curr->lfcnt)++;
            curr = curr->par;
        }
        (curr->lfcnt)++; //root
    }
}
node* trfind(string &ss)
{
    node *curr = root;
    for(int i = 0; i < ss.length(); i++)
    {
        if(curr->child[ss[i] - '0'] == nullptr) return nullptr;
        curr = curr->child[ss[i] - '0'];
    }
    return curr;
}
void trdel(string &ss)
{
    node* curr = trfind(ss);
    if(!curr) return;
    bool isonlyentry = false;
    if(curr->cnt==1) isonlyentry = true;
    while(curr->par)
    {
        (curr->cnt)--;
        if(isonlyentry) (curr->lfcnt)--;
        node *nxt = curr->par;
        if(curr->cnt==0) //DELETE THE NODE
        {
            char currch = curr->ch;
            curr->par->child[currch - '0'] = nullptr;
        }
        curr = nxt;
    } //Next 2 subtractions is on root
    (curr->cnt)--;
    if(isonlyentry) curr->lfcnt--;
}
int query(int y)
{
    string str = binstr(y);
    node *curr = root;
    int pw2 = (1<<B), ret = 0;
    for(int i = 0; i < B; i++)
    {
        pw2/=2;
        int bit = str[i] - '0';
        if(curr->child[bit] == nullptr)
        {
            return ret;
        }
        if(curr->child[bit]->lfcnt == pw2)
        {
            ret += pw2; //if all the possible values in next bit are there
            bit = 1 - bit; //dont go there, go to other bit and add this val :(
        }
        if(curr->child[bit] == nullptr) //if new child is also null
        {
            return ret; //then just return fml
        }
        curr = curr->child[bit]; //next child finally phew
    }
    return ret;
}
int n, q, a[N];
lint ans = 1, base = 1e8;
signed main()
{
    root = new node(nullptr, '2');
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        string binx = binstr(a[i]);
        trinsert(binx);
    }
    int x = 0;
    for(int i = 0; i < q; i++)
    {
        int typ, idx, y;
        cin >> typ;
        if(typ==1)
        {
            cin >> y;
            x ^= y;
        }
        else{
            cin >> idx >> y;
            string binx = binstr(a[idx]); //delete by OG value
            trdel(binx);
            a[idx] = y ^ x; //y is val after xoring with x so OG value = y^x
            binx = binstr(a[idx]);
            trinsert(binx);
        }
        int cans = query(x);
       // cout << cans << endl;
        ans*=modpow(base, cans, MOD);
        ans%=MOD;
    }
    cout << ans;
}