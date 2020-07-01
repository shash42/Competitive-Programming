#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
int r, c, n;
int boundary(int x, int y)
{
    int ret = -1;
    if(x==0) ret=y;
    else if(y==c) ret=c+x;
    else if(x==r) ret=c+r+(c-y);
    else if(y==0) ret=c+r+c+(r-x);
    return ret; 
}
vector< pii > v;
signed main()
{
    cin >> r >> c >> n;
    for(int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int pt1 = boundary(x1, y1);
        int pt2 = boundary(x2, y2);
        if(pt1 == -1 || pt2 == -1) continue;
        v.pb({pt1, i});
        v.pb({pt2, i});
    }
    sort(v.begin(), v.end());
    set<int> idxput;
    stack<int> stk;
    for(auto pt: v)
    {
        if(idxput.find(pt.S)==idxput.end())
        {
            idxput.insert(pt.S);
            stk.push(pt.S);
        }
        else
        {
            if(stk.top()!=pt.S)
            {
                cout << "NO";
                return 0;
            }
            stk.pop();
        }
    }
    cout << "YES";
}