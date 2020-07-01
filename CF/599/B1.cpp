#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=10003;

int n;
string s, t;
signed main()
{
	int k;
	cin >> k;
	while(k--)
	{
		cin >> n;
		cin >> s >> t;
		int cnt=0, ind1=-1, ind2=-1;
		for(int i = 0; i < n; i++)
		{
			if(s[i]!=t[i])
			{
				cnt++;
				if(cnt==1) ind1=i;
				else ind2=i;
			}
			if(cnt==3) break;
		}
	//	cout << cnt << " " << ind1 << " " << ind2 << endl;
		if(cnt==1 || cnt>2)
		{
			cout << "No\n";
			continue;
		}
		bool ltr[26], flag=false;
		if(cnt==0)
		{
			for(int i = 0; i < 26; i++) ltr[i]=false;
			for(int i = 0; i < n; i++)
			{
				if(ltr[s[i]]==true)
				{
					flag=true;
					break;
				}
				ltr[s[i]]=true;
			}
			if(flag)
			{
				cout << "Yes\n";
				continue;
			}
			else cout << "No\n";
			continue;
		}
		if(s[ind1]==s[ind2] && t[ind1]==t[ind2])
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}