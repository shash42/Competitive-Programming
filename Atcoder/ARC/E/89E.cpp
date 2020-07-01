#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=11, INF=1e9;
using namespace std;
int a, b, d[N][N], x[N][N], y[N][N], nodes = 2;
struct func
{
    int xc, yc, k;
};
struct edge
{
    int x, y, c;
};
vector<func> v;
vector<edge> ans;
signed main()
{
    cin >> a >> b;
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            cin >> d[i][j];
        }
    }
    for(int i = 1; i <= a; i++)
    {  
        for(int j = 1; j <= b; j++)
        {
            int chk = 1; // 0 - lost hope, 1 - need to add new node/edges, 2 - already done
            for(auto it: v)
            {
                if(it.xc * i + it.yc * j + it.k == d[i][j])
                {
                    chk = 2;
                }
                if(it.xc * i + it.yc * j + it.k < d[i][j])
                {
                    chk = 0;
                    break;
                }
            }
            if(chk==0)
            {
                cout << "Impossible";
                return 0;
            }
            else if(chk==2)
            {
                continue;
            }
            func mn={101, 101, 102};
            for(int ix = 0; ix <= 100; ix++)
            {
                for(int iy = 0; iy <= 100; iy++)
                {
                    int cost = ix*i + iy*j;
                    if(cost > d[i][j]) continue;
                    int kk = d[i][j] - cost;
                    //if(kk > mn.k) continue;
                    if(ix+iy > mn.xc + mn.yc) continue;
                    bool flag=true;
                    for(int ita = 1; ita <= a; ita++)
                    {
                        for(int itb = 1; itb <= b; itb++)
                        {
                            if(ix*ita + iy*itb + kk < d[ita][itb])
                            {
                                flag=false;
                                break;
                            }
                        }
                    }
                    if(flag)
                    {
                        mn={ix, iy, kk};
                    }
                }
            }
            if(mn.xc==101)
            {
                cout << "Impossible";
                return 0;
            }
            v.pb(mn);
        }
    }
   /* for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            cout << i << " " << j << " - " << x[i][j] << " " << y[i][j] << endl;
        }
    }*/
    for(auto it: v)
    {
        int curr = 1;
        for(int i = 0; i < it.xc; i++)
        {
            nodes++;
            ans.pb({curr, nodes, 101});
            curr = nodes;
        }
        for(int i = 0; i < it.yc; i++)
        {
            nodes++;
            ans.pb({curr, nodes, 102});
            curr = nodes;
        }
        ans.pb({curr, 2, it.k});
    }
    if(nodes>300) exit(7);
    cout << "Possible" << endl;
    cout << nodes << " " << ans.size() << endl;
    for(auto it: ans)
    {
        cout << it.x << " " << it.y << " ";
        if(it.c==101) cout << 'X';
        else if(it.c==102) cout << 'Y';
        else cout << it.c;
        cout << endl;
    }
    cout << 1 << " " << 2;
}