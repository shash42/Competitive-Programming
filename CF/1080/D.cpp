#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e6+5, INF=1e9;
using namespace std;
int n;
string s[N];
int val[N], l[N], r[N];
vector<int> * dfs(int u)
{
    if(s[u]=="IN")
    {
        vector<int> *ret = new vector<int>();
        ret->pb(u);
        return ret;
    }
    if(s[u]=="NOT")
    {
        vector<int> *ret = dfs(l[u]);
     //   cout << u << " - " << ret->size() << endl;
        val[u]=1-val[l[u]];
        return ret;
    }
    vector<int> *vl = dfs(l[u]);
    vector<int> *vr = dfs(r[u]);
    bool flipl = false, flipr = false;
    if(s[u]=="AND")
    {
        val[u]=val[l[u]] & val[r[u]];
        if(val[l[u]]) flipr = true;
        if(val[r[u]]) flipl = true;
    }    
    if(s[u]=="OR")
    {
        val[u]=val[l[u]] | val[r[u]];
        if(!val[l[u]]) flipr = true;
        if(!val[r[u]]) flipl = true;
    } 
    if(s[u]=="XOR")
    {
        val[u]=val[l[u]] ^ val[r[u]];
        flipr=flipl=true;
    }
  //  cout << u << " - " << flipl << " " << flipr << " " << vl->size() << " " << vr->size() << endl; 
    if(flipl^flipr)
    {
        if(flipl) return vl;
        return vr;
    }
    if(!(flipl||flipr))
    {
        vector<int> *ret = new vector<int>();
        return ret;
    }
    if(vl->size() > vr->size())
    {
        swap(vl, vr);
    }
    for(int i = 0; i < vl->size(); i++)
    {
        vr->pb(vl->at(i));
    }
    //cout << "both: " << vl->size() << " " << vr->size() << endl;
    return vr;
}
string ans;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> inp;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if(s[i]=="IN")
        {
            cin >> val[i];
            inp.pb(i);
        }
        else if(s[i]=="NOT")
        {
            cin >> l[i];
        }
        else
        {
            cin >> l[i] >> r[i];
        }
    }
    vector<int> &v = *(dfs(1));
    sort(v.begin(), v.end());
    /*for(int i = 1; i <= n; i++)
    {
        cout << val[i] << endl;
    }*/
    int curr=0;
    for(auto i: inp)
    {
        if(curr >= v.size() || i<v[curr])
        {
            ans+=('0'+val[1]);
        }
        else if(i==v[curr])
        {
            ans+=('0'+1-val[1]);
            curr++;
        }        
    }
    cout << ans;
}