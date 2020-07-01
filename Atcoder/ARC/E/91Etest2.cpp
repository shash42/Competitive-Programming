#include<bits/stdc++.h>
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
signed main()
{
    vector<int> ans;
    int n = 9;
    for(int i = 1; i <= n; i++)
    {
        v.pb(i);
    }
    int mn = INF;
    do
    {
        int li = lis(v);
        int ld = lds(v);
        if(li+ld<mn)
        {
            mn = li+ld;
            ans = v;
        }
    } while (next_permutation(v.begin(), v.begin()+n));
    cout << mn;
    for(auto it: ans)
    {
        cout << it << " ";
    }
}