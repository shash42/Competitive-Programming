#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=3e5+5, INF=1e9+9, T=19;
using namespace std;
int n, arr[1<<T], best=0;
pii mx1[1<<T], mx2[1<<T], best1, best2;
signed main()
{
    cin >> n;
    int l = 1<<n;
    for(int i = 0; i < l; i++)
    {
        cin >> arr[i];
    }
    mx1[0]={arr[0], 0};
    mx2[0]={-INF, -1};
    for(int i = 1; i < l; i++)
    {
        mx1[i]={arr[i], i};
        mx2[i]={-INF, -1};
        for(int j = 0; j < T; j++)
        {
            if(i & (1<<j))
            {
                int newi = i ^ (1<<j);
                if(mx1[newi].F > mx1[i].F)
                {
                    mx2[i] = mx1[i];
                    mx1[i]=mx1[newi];
                }
                if(mx1[newi] != mx1[i])
                {
                    if(mx1[newi].F > mx2[i].F)
                    {
                        mx2[i] = mx1[newi];
                    }
                }
                if(mx2[newi].F > mx2[i].F)
                {
                    mx2[i] = mx2[newi];
                }
            }
        }
        /*if(mx1[i].F > best1.F)
        {
            best2 = best1;
            best1=mx1[i];
        }
        if(mx1[i] != best1)
        {
            if(mx1[i].F > best2.F)
            {
                mx2[i] = mx1[newi];
            }
        }
        if(mx2[newi].F > mx2[i].F)
        {
            mx2[i] = mx2[newi];
        }*/
        best=max(best, mx1[i].F + mx2[i].F);
        cout << best << " ";
    }

}