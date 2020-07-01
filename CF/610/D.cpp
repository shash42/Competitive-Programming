#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int N=300, d[302];
string t;
string ans, finans;
signed main()
{
	int l;
	for(int i = 1; i <= N; i++)
	{
		t="";
		for(int j = 1; j <= i; j++)
		{
			t+='a';
		}
		string tmp = ans;
		reverse(tmp.begin(), tmp.end());
		t+=tmp;
		cout << t << endl;
		fflush(stdout);
		cin >> d[i];
		if(d[i]==-1) exit(0);
		if(d[i]==0)
		{
			return 0;
		}
		if(i==1) continue;
		if(d[i]<d[i-1]) continue;
		if(d[i]>d[i-1])
		{
			l=i-1;
			break;
		}
	}
	for(int i = 1; i <= l; i++) ans+='a';
	finans=ans;
	for(int i = l; i >= 1; i--)
	{
		t=ans;
		t[i-1]='b';
		cout << t << endl;
		fflush(stdout);
		int x;
		cin >> x;
		if(x==-1) exit(0);
		if(x==0) return 0;
		if(x<d[l]) finans[i-1]='b';
	}
	cout << finans << endl;
	fflush(stdout);
	int x;
	cin >> x;
	if(x!=0) exit(0);
}