#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=1e3+3, INF=1e9;
int dp[N][N], n=7;
vector< vector <int> > zeros, ones;
int solve(vector<int> a)
{
    for(int i = 0; i < n; i++)
    {
        dp[0][i]=a[i];
       // cout << dp[0][i] << " ";
    }
    //cout << endl;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n-i; j++)
        {
            dp[i][j]=abs(dp[i-1][j] - dp[i-1][j+1]);
         //   cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    return dp[n-1][0];
}
signed main()
{
    for(int i = 0; i < (1<<n); i++)
    {
        vector<int> temp;
        for(int j = 0; j < n; j++)
        {
            if(i&(1<<j))
            {
                temp.pb(1);
            }
            else temp.pb(0);
        }
        for(auto b: temp)
        {
            cout << b;
        }
        cout << " - " << solve(temp) << endl;
        if(solve(temp)==1)
        {
            ones.pb(temp);
        }
        else zeros.pb(temp);
    }
    /*cout << "Zeros: " << endl; 
    for(auto v: zeros)
    {
        for(auto b: v)
        {
            cout << b;
        }
        cout << endl;
    }
    cout << "Ones: " << endl; 
    for(auto v: ones)
    {
        for(auto b: v)
        {
            cout << b;
        }
        cout << endl;
    }*/
}