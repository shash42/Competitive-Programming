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

int n;

int main()
{
    int t;
    ind(t);
    while(t--)
    {
        ind(n);
        int x=0, y=1;
        int pos[3][3];
        pos[1][x]=1;
        pos[1][y]=1;
        pos[2][x]=2;
        pos[2][y]=1;
        bool valid=true;
        int last_tim=0;
        for(int a=1; a<=n; a++)
        {
            int xx, newpos[3][3];
            ind(xx);
            int tim=xx-last_tim;
            last_tim=xx;
            ind(newpos[1][x]);ind(newpos[1][y]);
            ind(newpos[2][x]);ind(newpos[2][y]);
            if(newpos[1][x]==newpos[2][x] && newpos[1][y]==newpos[2][y])
                valid=false;
            if(newpos[1][y]<pos[1][y] || newpos[2][y]<pos[2][y])
                valid=false;
            int req1=newpos[1][y]-pos[1][y]+abs(newpos[1][x]-pos[1][x]);
            int req2=newpos[2][y]-pos[2][y]+abs(newpos[2][x]-pos[2][x]);
            if(req1>tim || req2>tim)
                valid=false;
            pos[1][x]=newpos[1][x];
            pos[1][y]=newpos[1][y];
            pos[2][x]=newpos[2][x];
            pos[2][y]=newpos[2][y];
        }
        if(valid)
            printf("yes\n");
        else
            printf("no\n");
    }
	return 0;
}