#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n, a[N];
signed main()
{
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        if(n%i==0)
        {
            cout << i << n/i;
            return 0;
        }
    }
}