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

const int N=105;
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

int n, arr[N];
priority_queue<pair<int, int> >pq;

void ppush(pair<int, int> x)
{
    pq.push(x);
}

pair<int, int> ppop()
{
    pair<int, int> ret=pq.top();
    pq.pop();
    return ret;
}

char ans_array[10005][105];
int ans;

bool check()
{
    int here=1e9;
    for(int a=1; a<=n; a++)
        here=min(here, arr[a]);
    int not_here=0;
    for(int a=1; a<=n; a++)
    {
        if(arr[a]>here+1)
            return false;
        else if(arr[a]==here+1)
            not_here++;
    }
    return (not_here==3 || not_here==2 || not_here==0);
}

int main()
{
    ind(n);
    for(int a=1; a<=n; a++)
    {
        ind(arr[a]);
        for(int b=1; b<10005; b++)
            ans_array[b][a]='0';
    }
    for(int a=1; a<=n; a++)
        ppush({arr[a], a});
    while(1)
    {
        if(check())
            break;
        pair<int, int> here1=ppop();
        pair<int, int> here2=ppop();
        // if(ans<10)
        //     printf("%d %d\n", here1.f, here1.s);
        here1.f=max(here1.f-1, 0);
        here2.f=max(here2.f-1, 0);
        arr[here2.s]=here2.f;
        arr[here1.s]=here1.f;
        ans++;
        ans_array[ans][here1.s]='1';
        ans_array[ans][here2.s]='1';
        ppush(here1);
        ppush(here2);
        // printf("%d: \n", ans);
        // for(int a=1; a<=n; a++)
        //     printf("%d ", arr[a]);
        // printf("\n");
    }
    ans++;
    int mini=1e9;
    for(int a=1; a<=n; a++)
        mini=min(mini, arr[a]);
    int cnt=0;
    for(int a=1; a<=n; a++)
        if(arr[a]==mini+1)
        {
            ans_array[ans][a]='1';
            cnt++;
        }
    if(cnt==0)
        ans--;
    printf("%d\n%d\n", mini, ans);
    for(int a=1; a<=ans; a++)
        printf("%s\n", ans_array[a]+1);
	return 0;
}