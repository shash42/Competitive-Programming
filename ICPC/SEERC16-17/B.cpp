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
        if(n==1)
        {
            // printf("! 1 1\n");
            cout<<"! 1 1"<<endl;
            continue;
        }
        vector<int>maxi, mini;
        maxi.clear();
        mini.clear();
        for(int a=1; a<n; a+=2)
        {
            cout<<"? "<<a<<" "<<a+1<<endl;
            // printf("? %d %d\n", a, a+1);
            fflush(stdout);
            char x;
            // scanf("%c", &x);
            cin>>x;
            if(x=='>')
            {
                maxi.pb(a);
                mini.pb(a+1);
            }
            else
            {
                maxi.pb(a+1);
                mini.pb(a);
            }
        }
        int ans_maxi=maxi[0], ans_mini=mini[0];
        for(int a=1; a<maxi.size(); a++)
        {
            int p1=maxi[a];
            int p2=ans_maxi;
            // printf("? %d %d\n", p1, p2);
            cout<<"? "<<p1<<" "<<p2<<endl;
            fflush(stdout);
            char x;
            // scanf("%c", &x);
            cin>>x;
            if(x=='>')
                ans_maxi=maxi[a];
        }
        for(int a=1; a<mini.size(); a++)
        {
            int p1=mini[a];
            int p2=ans_mini;
            // printf("? %d %d\n", p1, p2);
            cout<<"? "<<p1<<" "<<p2<<endl;
            fflush(stdout);
            char x;
            // scanf("%c", &x);
            cin>>x;
            if(x=='<')
                ans_mini=mini[a];
        }
        if(n%2)
        {
            // printf("? %d %d\n", ans_maxi, n);
            cout<<"? "<<ans_maxi<<" "<<n<<endl;
            fflush(stdout);
            char x;
            // scanf("%c", &x);
            cin>>x;
            if(x=='<')
                ans_maxi=n;
            // printf("? %d %d\n", ans_mini, n);
            cout<<"? "<<ans_mini<<" "<<n<<endl;
            fflush(stdout);
            // scanf("%c", &x);
            cin>>x;
            if(x=='>')
                ans_mini=n;
        }
        // printf("! %d %d\n", ans_mini, ans_maxi);
        cout<<"! "<<ans_mini<<" "<<ans_maxi<<endl;
        fflush(stdout);
    }
	return 0;
}