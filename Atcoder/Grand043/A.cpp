#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=102, INF=1e9;
using namespace std;
int h, w, dist[N][N];
char mat[N][N];
deque< pii > dq;
signed main()
{
    cin >> h >> w;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i <= h; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            dist[i][j]=INF;
        }
    }
    dist[1][1]=(mat[1][1]=='#');
    dq.push_front({1, 1});
    while(dq.size())
    {
        pii u = dq.front();
        dq.pop_front();
        if(u.F!=h)
        {
            int curr = dist[u.F][u.S];
            if(mat[u.F][u.S]=='.' && mat[u.F+1][u.S]=='#') curr+=1;
            if(curr<dist[u.F+1][u.S])
            {
                dist[u.F+1][u.S]=curr;
                if(curr>dist[u.F][u.S]) dq.push_back({u.F+1, u.S});
                else dq.push_front({u.F+1, u.S});
            }
        }
        if(u.S!=w)
        {
            int curr = dist[u.F][u.S];
            if(mat[u.F][u.S]=='.' && mat[u.F][u.S+1]=='#') curr+=1;
            if(curr<dist[u.F][u.S+1])
            {
                dist[u.F][u.S+1]=curr;
                if(curr>dist[u.F][u.S]) dq.push_back({u.F, u.S+1});
                else dq.push_front({u.F, u.S+1});
            }
        }
    }
    /*for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cout << dist[i][j];
        }
        cout << endl;
    }*/
    cout << dist[h][w];
}