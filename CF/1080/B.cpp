#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=60, INF=1e9;
using namespace std;
int m, p, tr[N];
signed main()
{
    cin >> m >> p;
    for(int i = 1; i <= p; i++)
    {
        int x;
        cout << 1 << endl;
        fflush(stdout);
        cin >> x;
        if(x==0) exit(0);
        if(x==-2) exit(7);
        tr[i%p]=x;
    }
    int lo = 1, hi = m;
    for(int i = p+1; i <= N; i++)
    {
        int x;
        int mid = (lo+hi)/2;
        cout << mid << endl;
        fflush(stdout);
        cin >> x;
        if(x==0) exit(0);
        if(x==-2) exit(7);
        x = tr[i%p]*x;
        if(x==-1)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
}