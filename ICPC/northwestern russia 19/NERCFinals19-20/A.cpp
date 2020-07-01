#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define int long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=2e5+5;
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

int n, ans;
struct teacher
{
    int a, b, t;
} t[N];

struct tsrt
{
    bool operator()(const teacher &t1, const teacher &t2)
    {
        return t1.t > t2.t;
    }
};
struct tasrt
{
    bool operator()(const teacher &t1, const teacher &t2)
    {
        return t1.a < t2.a;
    }
}
priority_queue< teacher, vector < teacher >, tsrt> pq;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int lastb = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> t[i].a >> t[i].b >> t[i].t;
        lastb = max(t[i].b, lastb);
    }
    sort(t, t+n);
    teacher bs;
    bs.a = lastb+1, bs.t = 100000, bs.b = lastb + 1000000;
    pq.push(bs);
    int prev=0, timeptr=0;
    while(pq.size())
    {
        while(pq.size() && pq.top().a < prev)
        {
        //    cout << "lol: " << pq.top().a << " " << prev << endl;
            teacher curr = pq.top();
            pq.pop();
            if(prev + curr.t <= curr.b)
            {
                curr.a = prev;
                pq.push(curr);
            }
        }
        if(pq.size()==0) break;
        teacher curr = pq.top();
        if(curr.a == lastb+1) break;
        //cout << curr.a << " " << prev << endl;
        pq.pop();
        int take = (min(pq.top().a, curr.b) - curr.a) / curr.t;
        take = max(1LL, take);
        ans+=take;
        curr.a += curr.t * take;
        prev = curr.a;
        if(curr.a + curr.t <= curr.b)
        {
            //cout << "lol: " << curr.a << endl;
            pq.push(curr);
        }
    }
    cout << ans;
	return 0;
}