#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> KMP(string s)
{
	vector<int> pi (s.length());
	for(int i = 1; i < s.length(); i++)
	{
		pi[i].pb(0);
		j = pi[i-1];
		while(j!=0 && s[j]!=s[i])
		{
			j=pi[j-1];
		}
		pi[i] = j + (s[j]==s[i]);
	}
}
int main()
{
	
}