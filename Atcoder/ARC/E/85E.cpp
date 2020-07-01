#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=105, INF=1e9;
using namespace std;
int n, ans = 0, a[N];
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1e6; i >= 1; i--)
    {
        for(int i = n; i >= 1; i--)
        {
            int sum = 0;
            for(int j = i; j <= n; j+=i)
            {
                sum+=a[j];
            }
            if(sum<0)
            {
                for(int j = i; j <= n; j+=i)
                {
                    a[j]=0;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum+=a[i];
    }
    cout << sum;
}