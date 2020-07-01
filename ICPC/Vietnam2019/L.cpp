#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

string ender = "end.", Var="var", Print="print";
struct v
{
    bool eval=false;
    string expr="", value"";
};
vector<v> vlist;
map<v, int> M;
int vcnt=0;
void Var(string varinp)
{
    int itr=0;
    string varname, 
    while(varinp[itr]!=' ')
    {
        
    }
    vcnt++;
}
int main()
{
    string inp;
    cin >> inp;
    while(inp!=ender)
    {
        if(inp.compare(Var, 0, 3)==0)
        {
            Var(inp.begin()+4);
        }
        else
        {
            string outp="";
            outp+=compute(inp.begin()+6);
        }
        cin >> inp;
    }
	return 0;
}