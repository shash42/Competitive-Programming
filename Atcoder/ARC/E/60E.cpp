#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9, H=20;
using namespace std;
int n, x[N], l, q, nxt[N][H];
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    x[n+1]=2e9+9;
    cin >> l;
    for(int j = 0; j < H; j++)
    {
        nxt[n+1][j] = nxt[n][j] = n+1;
    }
    for(int i = n-1; i >= 1; i--)
    {
        int nxtt = i;    // last element <= l distance away
        for(int j = H-1; j >= 0; j--)
        {
            int pos = nxtt + (1<<j);
            if(pos>n) continue;
            if(x[pos]<=x[i] + l)
            {
                nxtt = pos;
            }
        }
        nxt[i][0]=nxtt;
        for(int j = 1; j < H; j++)
        {
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];
        }
    }
    /*cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(int j = 0; j < H; j++)
        {
            cout << nxt[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    cin >> q;
    for(int i = 0; i < q; i++)
    {
      //  cout << "query: " << i << endl;
        int a, b;
        cin >> a >> b;
        if(a>b) swap(a, b);
        int curr = a;
        int days = 0;
        for(int j = H-1; j >= 0; j--)
        {
         //   cout << curr << " " << j << " " << nxt[curr][j] << endl;
            if(nxt[curr][j] < b)
            {
                curr = nxt[curr][j];
                days += (1<<j);
            }
        }
        cout << days+1 << endl;
    }
}