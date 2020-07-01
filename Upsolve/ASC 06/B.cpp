#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
#define int long long
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 53, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, mat[N][N];
string inpt[N];
string NO = "Parts cannot be separated";
string YES = "Parts can be separated";
bool check(int i)
{
    bool in1 = false;
    for(int j = 0; j < inpt[i].length(); j++)
    {
        if(mat[i][j]==1){
           in1 = true;
        }
        else if(in1 && mat[i][j]==0){
            return true;
        }
    }
    return false;
}
signed main()
{
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    int t = 1;
    while(true)
    {
        cin >> n;
        if(n==0) break;
        cout << "Puzzle " << t++ << endl;
        for(int i = 1; i <= n; i++)
        {
            cin >> inpt[i];
            for(int j = 0; j < inpt[i].length(); j++)
            {
                mat[i][j] = inpt[i][j] - '0';
                //cout << mat[i][j];
            }
            //cout << endl;
        }
        bool no = false;
        for(int i = 1; i <= n; i++)
        {
            //cout << i << " " << no << endl;
            no |= check(i);
        }
        int cnt[2] = {0, 0};
        for(int j = 0; j < inpt[n].length(); j++){
            cnt[mat[n][j]]++;
        }
        //cout << cnt[0] << " " << cnt[1] << endl;
        //if(min(cnt[0], cnt[1])==0) no = true;
        if(no) {
            cout << NO << endl;
        }
        else cout << YES << endl;
        cout << endl;
    }
}