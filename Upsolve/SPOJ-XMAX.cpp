#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005, K = 62;
int n, arr[N], basis[K];
signed main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int tmp = arr[i];
        for(int j = K-1; j >= 0; j--)
        {
            if((1LL<<j) & tmp)
            {
                if(basis[j]!=0)
                {
                    tmp^=basis[j];
                }
                else
                {
                    basis[j]=tmp;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for(int i = K-1; i >= 0; i--)
    {
        if((ans^basis[i]) > ans)
        {
            ans^=basis[i];
        }
    }
    cout << ans;
}