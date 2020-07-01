#include<bits/stdc++.h>
#define int long long
#define inlld(a) scanf("%lld", &a)
#define f first
#define s second

using namespace std;

const int N=1004;

int ans=0;
int n;
set<pair<int, int> > adj[N];

set<pair<int, pair<int, int> > > s0, s1, s2;

void call_s1()
{
	auto it1=s1.rbegin();
	int weight_here=(*it1).f;
	ans+=weight_here;
	int end_point_1=(*it1).s.f;
	int end_point_2=(*it1).s.s;
	
	cout<<end_point_1<<" "<<end_point_2<<" "<<weight_here<<"\n";

	if(adj[end_point_1].find({weight_here, end_point_2})!=adj[end_point_1].end())
	{
		adj[end_point_1].erase({weight_here, end_point_2});
		auto to_take=adj[end_point_1].rbegin();
		int p=min((*to_take).s, end_point_1);
		int q=max((*to_take).s, end_point_1);
		pair<int, pair<int, int> > toremove={(*to_take).f, {p, q}};
		if(s0.find(toremove)!=s0.end())
		{
			s1.insert(toremove);
			s0.erase(toremove);
		}
		else if(s1.find(toremove)!=s1.end())
			s1.erase(toremove);
	}
}

void call_s0()
{
	auto it0=s0.rbegin();
	int weight_here=(*it0).f;
	// cout<<"ywsfs";
	ans+=2*weight_here;
	int end_point_1=(*it0).s.f;
	int end_point_2=(*it0).s.s;

	cout<<end_point_1<<" "<<end_point_2<<" "<<weight_here<<"\n";
	
	adj[end_point_1].erase({weight_here, end_point_2});
	adj[end_point_2].erase({weight_here, end_point_1});
	
	printf("0\n");

	auto to_take_1=adj[end_point_1].rbegin();
	auto to_take_2=adj[end_point_2].rbegin();
	
	printf("1\n");

	int p=min((*to_take_1).s, end_point_1);
	int q=max((*to_take_1).s, end_point_1);
	pair<int, pair<int, int> > toremove={(*to_take_1).f, {p, q}};
	
	printf("2\n");

	if(s0.find(toremove)!=s0.end())
	{
		s1.insert(toremove);
		s0.erase(toremove);
	}
	else
		s1.erase(toremove);
	
	printf("1\n");

	p=min((*to_take_2).s, end_point_2);
	q=max((*to_take_2).s, end_point_2);
	toremove={(*to_take_2).f, {p, q}};
	if(s0.find(toremove)!=s0.end())
	{
		s1.insert(toremove);
		s0.erase(toremove);
	}
	else if(s1.find(toremove)!=s1.end())
		s1.erase(toremove);

	adj[end_point_1].erase({(*to_take_1).f, (*to_take_1).s});
	adj[end_point_2].erase({(*to_take_2).f, (*to_take_2).s});
}

signed main()
{
	inlld(n);
	for(int a=0; a<(n*(n-1))/2; a++)
	{
		int u, v, w;
		inlld(u);inlld(v);inlld(w);
		// adj[u].pb({v, w});
		adj[u].insert({w, v});
		s0.insert({w, {min(u, v), max(u, v)}});
		// printf("%lld\n", a);
	}
	while(!s0.empty() || !s1.empty())
	{
		if(s0.empty())
		{
			call_s1();
			continue;
		}
		else if(s1.empty())
		{
			call_s0();
			continue;
		}

		auto it0=s0.rbegin();
		auto it1=s1.rbegin();
		if((*it0).f > (*it1).f)
			call_s0();	
		else
			call_s1();
	}
	printf("%lld\n", ans);
	return 0;
}