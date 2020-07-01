#include<bits/stdc++.h>

using namespace std;

const int N = 102;
int n, arr[N], d;
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = arr[0];
        int days = d;
        for(int i = 1; i < n; i++)
        {
            if(i*arr[i] <= days)
            {
                days -= i*arr[i];
                ans += (arr[i]);
            }
            else
            {
                ans += days/i;
                break;
            }
        }
        cout << ans << endl;
    }
}