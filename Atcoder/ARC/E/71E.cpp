#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
int q, cnt[2][2][N]; //string, letter, index
string s[2];
signed main()
{
    cin >> s[0] >> s[1];
    int l[] = {s[0].length(), s[1].length()};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cnt[i][j][0]=0;
        }
    }
    for(int sn = 0; sn < 2; sn++)
    {
        for(int i = 1; i <= l[sn]; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cnt[sn][j][i] = cnt[sn][j][i-1] + (s[sn][i-1] == ('A'+j));
            }
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int tot1 = cnt[0][0][b] - cnt[0][0][a-1];
        tot1 += 2*(cnt[0][1][b] - cnt[0][1][a-1]); 
        int tot2 = cnt[1][0][d] - cnt[1][0][c-1];
        tot2 += 2*(cnt[1][1][d] - cnt[1][1][c-1]);
        if(tot1%3 == tot2%3)
        {
            cout << "YES\n";
        } 
        else
        {
            cout << "NO\n";
        }
        
    }
}