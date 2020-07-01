#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;
string s, t;
const int N=2e5+5;
int s1[N], s2[N], flag=1, n, nxt[2], nxtm[2];
vector< pii > V;
signed main()
{
	cin >> n;
	cin >> s >> t;
	for(int i = 0; i < s.length(); i++)
	{
		s1[i]=(s[i]=='b');
	}
	for(int i = 0; i < t.length(); i++)
	{
		s2[i]=(t[i]=='b');
	}
	nxt[0]=nxt[1]=-1;
	nxtm[0]=nxtm[1]=-1;
	for(int i = 0; i < n; i++)
	{
		if(nxt[0]<=i) nxt[0]=i+1;
		if(nxt[1]<=i) nxt[1]=i+1;
		if(nxtm[0]<=i) nxtm[0]=i+1;
		if(nxtm[1]<=i) nxtm[1]=i+1;
		if(s1[i]!=s2[i])
		{
			while(nxt[s1[i]]!=n && (s1[nxt[s1[i]]]!=s1[i] || s1[nxt[s1[i]]]==s2[nxt[s1[i]]]))
			{
				nxt[s1[i]]++;
			}
		//	cout << i << " " << nxt[s1[i]] << endl;
			if(nxt[s1[i]]==n)
			{
				while(nxtm[s1[i]]!=n && s1[nxtm[s1[i]]]!=s1[i])
				{
					nxtm[s1[i]]++;
				}
				if(nxtm[s1[i]]==n)
				{
					flag=0;
					break;
				}
				s1[nxtm[s1[i]]]=1-s1[i];
				V.pb(mp(nxtm[s1[i]], i));
			}
			else
			{
				s1[nxt[s1[i]]]=1-s1[i];
				V.pb(mp(nxt[s1[i]], i));
			}
			s2[i]=1-s1[i];
		}
	}
	if(!flag)
	{
		cout << -1;
		return 0;
	}
	cout << V.size() << endl;
	for(auto &x: V)
	{
		cout << x.first+1 << " " << x.second+1 << endl; 
	}
}