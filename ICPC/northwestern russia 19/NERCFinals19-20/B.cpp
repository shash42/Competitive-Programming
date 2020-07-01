#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define pii pair<int, int>
using namespace std;

string s;
vector<pair < char, int > > ps;
int main()
{
	cin >> s;
	int cnt = 1;
	for(int i = 1; i < s.length(); i++)
	{
		if(s[i]!=s[i-1])
		{
			ps.pb(mp(s[i-1], cnt));
			cnt = 0;
		}
		cnt++;
	}
	ps.pb(mp(s[s.length()-1], cnt));
	//for(auto p: ps) cout << p.F << " " << p.S << endl;
	if(ps.size()%2==0)
	{
		cout << 0;
		return 0;
	}
	int n = ps.size();
	int ptr = n/2;
	if(ps[ptr].S<2)
	{
		cout << 0;
		return 0;
	}
	int ptr1=ptr-1, ptr2=ptr+1;
	bool flag=true;
	while(ptr1>=0 && ptr2<n)
	{
		if(ps[ptr1].F != ps[ptr2].F || ps[ptr1].S + ps[ptr2].S < 3)
		{
			flag=false;
			break;
		}
		ptr1--;
		ptr2++;
	}
	if(ptr1>=0) flag=false;
	if(ptr2<n) flag=false;
	if(flag)
	{
		cout << ps[ptr].S+1;
	}
	else
	{
		cout << 0;
	}
}