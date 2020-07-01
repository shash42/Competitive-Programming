#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N=1e5+5;

int cnt[4], tmp[4], p[4], b[4], c[4];
vector<int> ans;
void outp()
{
	cout << "YES\n";
	for(auto v: ans)	cout << v << " ";
}
void rest()
{
	ans.clear();
	for(int i = 0; i < 4; i++) tmp[i]=cnt[i];
}
bool chk()
{
	bool flag=true;
	for(int i = 0; i < 4; i++)		if(tmp[i]!=0) flag=false;
	return flag;	
}
bool solve(int x)
{	
	tmp[x]--;
	ans.pb(x);
	if(x==0 || x==3)
	{
		if(tmp[p[x]]==0) return chk();
		return solve(p[x]);
	}
	if(tmp[c[x]]!=0)	return solve(c[x]);
	else if(tmp[b[x]]!=0)	return solve(b[x]);
	else return chk();
}
int main()
{
	bool flag=false;
	cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
	rest();
	p[0]=1, p[3]=2, b[1]=2, b[2]=1, c[1]=0, c[2]=3;
	for(int i = 0; i < 4; i++)
	{
		flag=solve(i);
		if(flag)
		{
			outp();
			return 0;
		}
		rest();
	}
	cout << "NO\n";
 }