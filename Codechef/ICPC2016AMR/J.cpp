#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
string inp, s;
stack <int> stk;
int close[N], l;
int solve(int l, int r)
{
	if(r-l==1) return 1;
	if(l>r) return 0;
	int ret = 0;
	int en = l+1;
	while(en<r)
	{
		ret ^= solve(en, close[en]);
		en=close[en]+1;
	}
	return ret+1;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> inp;
		s="(";
		s+=inp;
		s+=")";
		l = s.length();
		for(int i = 0; i < l; i++)
		{
			if(s[i]=='(') stk.push(i);
			else
			{
				close[stk.top()]=i;
				stk.pop();
			}
		}
		int ans = solve(0, l-1);
		ans--;
		if(ans==0) cout << "Bob\n";
		else cout << "ATM\n";
	}	
}