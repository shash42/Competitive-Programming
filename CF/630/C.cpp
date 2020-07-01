#include<bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5+5;
int n, k, t, cnt[N][26];
string s;
signed main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> s;
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                cnt[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            int j = i%k;
            if(j >= k/2 + (k%2!=0))
            {
                j = k - j - 1;
            }
            cnt[j][s[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0; i <= k/2 - (k%2==0); i++)
        {
            int mx = 0;
            for(int j = 0; j < 26; j++)
            {
                mx = max(mx, cnt[i][j]);
            }
            if(k%2==1 && i == k/2) ans += (n/k) - mx;
            else ans += (2*n/k) - mx;
        }
        cout << ans << endl;
    }
}