#include<iostream>
#include<vector>
#include<utility>
#include<string>
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

const int N = 1e5 + 5, M = 1e4 + 5, A = 27, K = 50;
const int INF = 1e9;

struct node
{
    bool isend = false;
    node *child[A];
    node *par = nullptr;
    int cnt = 0;
    node(node *parr)
    {
        par =  parr;
        for(int i = 0; i < A; i++)
        {
            child[i] = nullptr;
        }
    }
} *root;
void trinsert(string &ss)
{
    node *curr = root;
    for(int i = 0; i < ss.length(); i++)
    {
        if(curr->child[ss[i] - 'a'] == nullptr)
        {
            curr->child[ss[i] - 'a'] = new node(curr);
        }
        curr = curr->child[ss[i] - 'a'];
        curr->cnt++;
    }
    curr->isend = true;
}
node* trfind(string &ss)
{
    node *curr = root;
    for(int i = 0; i < ss.length(); i++)
    {
        if(curr->child[ss[i] - 'a'] == nullptr) return nullptr;
        curr = curr->child[ss[i] - 'a'];
    }
    return curr;
}
void trdel(string &ss)
{
    node* curr = trfind(ss);
    if(!curr) return;
    while(curr->par)
    {
        curr->cnt--;
        node *nxt = curr->par;
        if(curr->cnt==0) delete(curr);
        curr = nxt;
    }
}
int n, dp[N];
string inp, s = " ", pens[M];
signed main()
{
    root = new node(nullptr);
    cin >> inp;
    s += inp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> pens[i];
        trinsert(pens[i]);
    }
    dp[0] = 0;
    for(int i = 1; i < s.length(); i++)
    {
        dp[i] = INF;
        for(int j = i-1; j >= i - K; j--)
        {
            if(j<0) break;
            string ss = s.substr(j+1, i - j);
            if(trfind(ss))
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    if(dp[s.length() - 1] >= INF) cout << -1;
    else cout << dp[s.length() - 1];
}

