#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=55, INF=1e9;
using namespace std;
int n, x;
priority_queue< int > pq;
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        pq.push(x);
    }
    int ops=0;
    while(true)
    {
        int a = pq.top();
        pq.pop();
        a+=ops;
        if(a<n) break;
        ops+=a/n;
        //cout << a << " " << ops << endl;
        a=a%n;
        a-=ops;
        pq.push(a);
    }
    cout << ops;
}