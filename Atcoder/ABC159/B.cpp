#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=1e5+3, INF=1e9;
string s;
bool check(string p)
{
    bool ret = true;
    int i = 0, j = p.length()-1;
    while(j>=i)
    {
        if(p[i]!=p[j]) ret = false;
        i++;
        j--;
    }
    return ret;
}
signed main()
{
    cin >> s;
    int n = s.length();
    bool ans = true;
    if(!check(s)) ans=false;
    string t = "";
    for(int i = 0; i < (n-1)/2; i++)
    {
        t+=s[i];
    }
    if(!check(t)) ans = false;
    t = "";
    for(int i = (n+3)/2 - 1; i < n; i++)
    {
        t+=s[i];
    }
    if(!check(t)) ans = false;
    if(ans)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}