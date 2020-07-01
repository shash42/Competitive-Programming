#include<bits/stdc++.h>
#define pb push_back
#define joel int
using namespace std;

const joel N=1e5+5, INF=1e9;
joel n, m, pat[N], arr[N];
vector < joel > texts[N];
set < joel > active;
vector<joel> KMP(vector<joel> v, joel l)
{
	vector<joel> pi (l);
	for(joel i = 1; i < l; i++)
	{
		joel j = pi[i-1];
		while(j!=0 && v[j]!=v[i])
		{
			j=pi[j-1];
		}
		pi[i] = j + (v[j]==v[i]);
	}
	return pi;
}
void push(joel x, joel y)
{
	set <joel> curr;
	for(joel i = 1; i*i <= y; i++) //factors ko daalo curr me
	{
		if(y%i) continue;
		if(i*i!=y) curr.insert(i);
		curr.insert(y/i);
	}
	for(auto it: active) //jo nonfactors purane actives pade hain unme jitni baar x ghusasakte hain ghusao
	{
		if(y%it==0) continue;
		for(joel j = 0; j < y/it; j++)
		{
			texts[it].pb(x);
		}
		texts[it].pb(INF);
	}
	for(joel i = 1; i < y; i++) //jo 1...y me active nahi hai and doesnt divide push it in curr too.
	{
	//	if(active.find(i)!=active.end()) continue;
		if(y%i==0) continue;
		curr.insert(i);
	}
	for(auto it: curr)
	{
	//	if(active.find(it)!=active.end()) active.erase(it); //jo factors hain unhe to continue hi kar rahe hain so dont have to deactivate
		for(joel i = 0; i < y/it; i++) texts[it].pb(x); //suffix se uthake start karne ke barabar hogaya ye vala part
	}
	active.clear();
	for(auto it: curr) active.insert(it);
	curr.clear();
}
joel main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	joel t;
	cin >> t;
	while(t--)
	{
		for(joel i = 0; i < N; i++) texts[i].clear();
		joel ans = 0;
		cin >> n >> m;
		for(joel i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		joel cnt=1;
		for(joel i = 1; i < n; i++)
		{
			if(arr[i]==arr[i-1])
			{
				cnt++;
			}
			else if(arr[i]!=arr[i-1])
			{
				push(arr[i-1], cnt);
				cnt=1;
			}
		}
		push(arr[n-1], cnt);
		active.clear();
		for(joel i = 0; i < m; i++)
		{
			cin >> pat[i];
		}
		for(joel i = 1; i <= n; i++)
		{
			if(texts[i].size()<m) continue;
			/*cout << i << " - ";
			for(auto p: texts[i])
			{
				cout << p << " ";
			}
			cout << endl;*/
			vector<joel> v;
			for(joel j = 0; j < m; j++) v.pb(pat[j]);
			v.pb(INF);
			for(joel j = 0; j < texts[i].size(); j++) v.pb(texts[i][j]);
			vector<joel> ret = KMP(v, v.size());
			for(auto lol: ret)
			{
				if(lol==m) ans++;
			}
		}
		cout << ans << endl;	
	}
}