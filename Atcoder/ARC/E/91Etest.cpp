#include<bits/stdc++.h>
#define int long long 
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=3e5+5, INF=1e9+9;
using namespace std;
vector<int> v, rem;
int lis(vector<int> arr)
{
    set<pii> St;
    set<pii>::iterator it;
    St.insert({-INF, 0});
    for(int i = 0; i < arr.size(); i++)
    {
        it = St.lower_bound({arr[i], 0});
        it--;
        int prev = it->F, prevl=it->S;
        it++;
        if(arr[i] > prev && (it==St.end() || arr[i] < it->F))
        {
            if(it!=St.end()) St.erase(it);
            St.insert({arr[i], prevl+1});
        }
    }
    it = St.end();
    it--;
    return it->S;
}
int lds(vector<int> arr)
{
    set<pii> St;
    set<pii>::iterator it;
    St.insert({-INF, 0});
    for(int i = 0; i < arr.size(); i++)
    {
        it = St.lower_bound({-arr[i], 0});
        it--;
        int prev = it->F * -1, prevl=it->S;
        it++;
        if(arr[i] < prev && (it==St.end() || arr[i] > it->F * -1))
        {
            if(it!=St.end()) St.erase(it);
            St.insert({-arr[i], prevl+1});
        }
    }
    it = St.end();
    it--;
    return it->S;
}
int solve(int n, int a, int b)
{
    v.clear();
    if(a + b - 1 > n)
    {
    //    cout << -1;
        return 0;
    }
    if(a*b<n)
    {
      //  cout << -1;
        return 0;
    }

    for(int i = b; i >= 1; i--) //LDS
    {
        v.pb(i);
    }
    int curr = b;
    for(int i = 1; i < a; i++)
    {
        int currsz = (n - curr) / (a-i) + ((n - curr) % (a-i)!=0);
        for(int j = curr + currsz; j > curr; j--)
        {
            v.pb(j);
        }
        curr = curr+currsz;
    }
    int li = lis(v);
    int ld = lds(v);
    if(li != a || ld != b)
    {
        cout << endl << "Machi bakchodi: " << n << " " << a << " " << b << endl;
        for(auto it: v)
        {
            cout << it << " ";
        } 
        cout << endl << li << " - " << ld << endl;
    }
}
signed main()
{
    for(int i = 2; i <= 100; i++)
    {
        cout << i << endl;
        for(int j = 2; j <= i; j++)
        {
            for(int k = 2; k <= i; k++)
            {
                solve(i, j, k);
            }
        }
    }
}   