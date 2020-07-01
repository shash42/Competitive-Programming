#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=405, INF=1e9;
using namespace std;
int n, ans = 0, c[N][4];
map<array<int, 4>, int> mp;
vector< array<int, 4> > rottn;
int match(array<int, 4> x, array<int, 4> y)
{
    int ret = 0;
    for(int i = 0; i < 4; i++)
    {
        array<int, 4> tmp;
        for(int j = 0; j < 4; j++)
        {
            tmp[j] = y[(j+i)%4];
        }
        if(tmp==x) ret++;
    }
    return ret;
}
void print(array<int, 4> a)
{
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
}
signed main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(auto opp: rottn)
        {
            vector< array<int, 4> > prevo;
            array<int, 4> ori[4];
            ori[0] = {opp[1], opp[0], c[i][1], c[i][0]};
            ori[1] = {opp[3], opp[2], c[i][3], c[i][2]};
            ori[2] = {opp[0], opp[3], c[i][2], c[i][1]};
            ori[3] = {opp[2], opp[1], c[i][0], c[i][3]};
            int cnt = 1;
            prevo.pb(opp);
            for(int j = 0; j < 4; j++)
            {
                int tmpsum = mp[ori[j]];
                for(auto prev: prevo) tmpsum -= match(ori[j], prev);
                prevo.pb(ori[j]);
                cnt*=tmpsum;
            }
            ans += cnt;
        }
        for(int j = 0; j < 4; j++)
        {
            array<int, 4> tbp;
            for(int k = 0; k < 4; k++)
            {
                tbp[k] = c[i][(j+k)%4];
            }
            rottn.pb(tbp);
            mp[tbp]++;
        }
    }
    cout << ans;
}