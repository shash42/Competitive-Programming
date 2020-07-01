#include<bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5+5;
int a, b, c, d, x, y, x1, y11, x2, y2;
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;
        cin >> x >>  y >> x1 >> y11 >> x2 >> y2;
        if( (x + b - a < x1)  || (x + b - a > x2) )
        {
            cout << "NO\n";
            continue;
        }
        if( (y + d - c < y11)  || (y + d - c > y2) )
        {
            cout << "NO\n";
            continue;
        }
        if(y11==y2 && (d>0))
        {
            cout << "NO\n";
            continue;
        }
        if(x1==x2 && (b>0))
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}