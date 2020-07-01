#include<bits/stdc++.h>
#define pb push_back
using namespace std;

string s="", t, kmpinp="", inps, inp2="";
int selfkmptmp;

vector<int> KMP(string S)
{
	vector<int> pi(S.length()+1, 0);
	for(int i = 1; i < S.length(); i++)
	{
		int j = pi[i-1];
		while(S[j]!=S[i] && j)
		{
			j=pi[j-1];
		}
		pi[i]= j + (S[i]==S[j]);
	}
	vector<int> occ;
	for(int i = 0; i < S.length(); i++)
	{
		if(pi[i]==t.length())
		{
			occ.pb(i);
		}
	}
	return occ;
}
int solve(vector<int> occ)
{
	vector<int> dp(occ.size() + 1);
	int ptr=0;
	int ret = (occ.size()>0);
	dp[0] = (occ.size()>0);
	for(int i = 1; i < occ.size(); i++)
	{
		while(occ[i]-occ[ptr]>t.length()) ptr++;
		if(occ[i]-occ[ptr]==t.length())
		{
			dp[i]=dp[ptr]+1;
			ret=max(ret, dp[i]);
		}
		else
		{
			dp[i] = 1;
		}
	}
	return ret;
}
int main()
{
	cin >> inps >> t;
	while(inp2.length() < t.length())
	{
		inp2+=inps;
	}
	s+=inp2;
	s+=inp2;
	kmpinp+=t;
	kmpinp+="#";
	kmpinp+=s;
	//kmpinp+=s;
	//cout << kmpinp << endl;
	vector<int> occ1 = KMP(kmpinp);
	// for(auto v: occ1) cout << v << " ";
	// 	cout << endl;
	kmpinp+=inp2;
	//cout << kmpinp << endl;
	vector<int> occ2 = KMP(kmpinp);
	// for(auto v: occ2) cout << v << " ";
	// 	cout << endl;
	int pow1=solve(occ1), pow2=solve(occ2);
	if(pow2!=pow1) 
	{	
		cout << -1;
		return 0;
	}
	cout << pow1;
}