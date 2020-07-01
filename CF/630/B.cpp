#include<bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e3+5;
int n, m, a[N], c[N], comp[N], col;
signed main()
{
    for(int i = 2; i < N; i++)
    {
        if(comp[i]) continue;
        for(int j = 2*i; j < N; j+=i)
        {
            comp[j]=1;
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        col=0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            c[i]=0;
        }
        for(int i = 2; i < N; i++)
        {
            if(comp[i]) continue;
           // cout << "prime: " << i << endl;
            int notused = 1;
            for(int j = 1; j <= n; j++)
            {
                if(c[j]==0 && a[j] % i == 0)
                {
                    col += notused;
                    notused=0;
                    c[j] = col;
                }
            }
        }
        cout << col << endl;
        for(int i = 1; i <= n; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
    }
}