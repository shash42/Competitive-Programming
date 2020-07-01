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
int k, m, arr[1000005];
signed main()
{
    cin >> m >> k;
    if(k>=(1<<m))
    {
        cout << -1;
        return 0;
    }
    if(m==0)
    {
        if(k==0)
        {
            cout << 0 << " " << 0;
        } 
        else
        {
            cout << -1;
        }
        return 0;
    }
    if(m==1)
    {
        if(k==0)
        {
            cout << 0 << " " << 0 << " " << 1 << " " << 1;
        }
        else
        {
            cout << -1;
        }
        return 0;
    }
    int n = (1<<(m+1));
    if(k==0)
    {
        for(int i = 0; i < n; i+=2)
        {
            arr[i]=arr[i+1]=i/2;
        }
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return 0;
    }
    arr[0]=arr[2]=0;
    arr[1]=k;
    int cnt=0;
    for(int i = 1; i < n/2; i++)
    {
        if(i==k)
        {
            cnt=1;
            continue;
        }
        arr[2+i-cnt]=i;
    }
    arr[n/2+1]=k;
    cnt=0;
    int ptr=1;
    for(int i = n-1; i > n/2+1; i--)
    {
        if(ptr==k)
        {
            ptr++;
        }
        arr[i]=ptr;
        ptr++;
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}