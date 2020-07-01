#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=62;
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

int r, c;

string mat[N];

bool check(int x)
{
    if(x==0)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j]=='P') return false;
            }
        }
        return true;
    }
    if(x==4)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j]=='A') return true;
            }
        }
        return false;   
    }
    if(x==1)
    {
        for(int i = 0; i < r; i++)
        {
            if(mat[i][0]=='P') break;
            if(i==r-1) return true;
        }
        for(int i = 0; i < r; i++)
        {
            if(mat[i][c-1]=='P') break;
            if(i==r-1) return true;
        }
        for(int i = 0; i < c; i++)
        {
            if(mat[0][i]=='P') break;
            if(i==c-1) return true;
        }
        for(int i = 0; i < c; i++)
        {
            if(mat[r-1][i]=='P') break;
            if(i==c-1) return true;
        }
        return false;
    }
    if(x==2)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j]=='P') break;
                if(j==c-1) return true;
            }
        }
        for(int i = 0; i < c; i++)
        {
            for(int j = 0; j < r; j++)
            {
                if(mat[j][i]=='P') break;
                if(j==r-1) return true;
            }
        }
        if(mat[0][0]=='A' || mat[r-1][c-1]=='A' || mat[0][c-1] == 'A' || mat[r-1][0]=='A') return true;
        return false;
    }
    for(int i = 0; i < r; i++)
    {
        if(mat[i][0]=='A') return true;
    }
    for(int i = 0; i < r; i++)
    {
        if(mat[i][c-1]=='A') return true;
    }
    for(int i = 0; i < c; i++)
    {
        if(mat[0][i]=='A') return true;
    }
    for(int i = 0; i < c; i++)
    {
        if(mat[r-1][i]=='A') return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> r >> c;
        for(int i = 0; i < r; i++) cin >> mat[i];
        bool flag=false;
        for(int i = 0; i <= 4; i++)
        {
            flag=check(i);
            if(flag)
            {
                cout << i << endl;
                break;
            }
        }
        if(!flag)
        {
            cout << "MORTAL" << endl;
        }
    }
	return 0;
}