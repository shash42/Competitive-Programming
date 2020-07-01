#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

lint _add(lint x, lint y)
{
    lint ret=x+y;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

lint _mult(lint x, lint y)
{
    x%=MOD;
    y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int arr[30][4];
bool adj[N][N];

bool diff(int x, int y)
{
    bool ret=true;
    for(int a=1; a<=4; a++)
    {
        int x1=0, x2=0;
        while(arr[x][x1]!=a)
            x1++;
        while(arr[y][x2]!=a)
            x2++;
        ret&=(abs(x1-x2)<=1);
    }
    return ret;
}

int par[30];
bool yo=false;

void dfs(int u, int mask)
{
    if(yo)
        return;
    if(mask+1==(1<<24))
    {
        int x=u;
        while(x!=1)
        {
            for(int a=0; a<4; a++)
                printf("%d ", arr[x][a]);
            printf("\n");
            x=par[x];
        }
        yo=true;
        return;
    }
    for(int a=0; a<24; a++)
        if(adj[u][a] && (mask&(1<<a))==0)
        {
            par[a]=u;
            dfs(a, mask+(1<<a));
            if(yo)
                return;
        }
}

int main()
{
    int cnt=0;
    for(int a=1; a<=4; a++)
        for(int b=1; b<=4; b++)
            for(int c=1; c<=4; c++)
                for(int d=1; d<=4; d++)
                {
                    if(a==b || a==c || a==d || b==c || b==d || c==d)
                        continue;
                    arr[cnt][0]=a;
                    arr[cnt][1]=b;
                    arr[cnt][2]=c;
                    arr[cnt][3]=d;
                    cnt++;
                }
    for(int a=0; a<24; a++)
        for(int b=0; b<24; b++)
            adj[a][b]=false;
    for(int a=0; a<cnt; a++)
        for(int b=0; b<cnt; b++)
            if(diff(a, b) && a!=b)
            {
                adj[a][b]=adj[b][a]=true;
                // adj[a].pb(b);
                // adj[b].pb(a);
                // for(int c=0; c<4; c++)
                //     printf("%d ", arr[a][c]);
                // printf("\n");
                // for(int c=0; c<4; c++)
                //     printf("%d ", arr[b][c]);
                // printf("\n\n");
            }
    dfs(0,1);
    return 0;
}