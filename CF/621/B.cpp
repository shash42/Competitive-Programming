#include<bits/stdc++.h>

using namespace std;

const int N = 100002;
int n, arr[N], x;
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int ans=0, mx=0;
        cin >> n >> x;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mx = max(mx, arr[i]);
            if(x==arr[i])
            {
                ans = 1;
            }
        }
        if(ans)
        {
            cout << ans << endl;
            continue;
        }
        if(x < mx)
        {
            cout << 2 << endl;
            continue;
        }
        ans = (x / mx) + (x % mx != 0);
        cout << ans << endl;
    }
}