#include<bits/stdc++.h>
#define ind(a) scanf("%d", &a)
#define pb push_back
#define s second
#define f first

using namespace std;

const int N=105;

int n, m, h, ans_max, ans_min;
char nm[N][N], nh[N][N];
vector<pair<int, pair<int, int > > >vec_max, vec_min;

void solve_max(int height)
{
	int cnt1=0, cnt2=0;
	for(int a=0; a<m; a++)
		cnt1+=(nm[height][a]=='1');
	for(int a=0; a<h; a++)
		cnt2+=(nh[height][a]=='1');
	if(min(cnt1, cnt2)==0 && max(cnt1, cnt2)!=0)
	{
		printf("-1\n");
		exit(0);
	}
	ans_max+=cnt1*cnt2;
	for(int a=0; a<m; a++)
		for(int b=0; b<h; b++)
			if(nm[height][a]==nh[height][b] && nm[height][a]=='1')
				vec_max.pb({height, {a, b}});
}

void solve_min(int height)
{
	int cnt1=0, cnt2=0;
	for(int a=0; a<m; a++)
		cnt1+=(nm[height][a]=='1');
	for(int a=0; a<h; a++)
		cnt2+=(nh[height][a]=='1');
	ans_min+=max(cnt1, cnt2);
	if(cnt2<cnt1)
	{
		int given=0;
		vector<int>alongh, alongm;
		for(int a=0; a<h; a++)
			if(nh[height][a]=='1')
				alongh.pb(a);
		for(int a=0; a<m; a++)
			if(nm[height][a]=='1')
				alongm.pb(a);
		int ptr=0;
		for(auto x:alongm)
		{
			if(given==cnt1-cnt2+1)
			{
				ptr++;
				vec_min.pb({height, {x, alongh[ptr]}});
				// ptr++;
			}
			else
			{
				vec_min.pb({height, {x, alongh[ptr]}});
				given++;
			}
		}
	}
	else
	{
		int given=0;
		vector<int>alongh, alongm;
		for(int a=0; a<h; a++)
			if(nh[height][a]=='1')
				alongh.pb(a);
		for(int a=0; a<m; a++)
			if(nm[height][a]=='1')
				alongm.pb(a);
		int ptr=0;
		for(auto x:alongh)
		{
			if(given==cnt2-cnt1+1)
			{
				ptr++;
				vec_min.pb({height, {alongm[ptr], x}});
				// ptr++;
			}
			else
			{
				vec_min.pb({height, {alongm[ptr], x}});
				given++;
			}
		}
	}
}

int main()
{
	ind(n);ind(m);ind(h);
	for(int a=0; a<n; a++)
		scanf(" %s", nm[a]);
	for(int a=0; a<n; a++)
		scanf(" %s", nh[a]);
	for(int a=0; a<n; a++)
		solve_max(a);
	sort(vec_max.begin(), vec_max.end());
	printf("%d\n", ans_max);
	for(auto x:vec_max)
		printf("%d %d %d\n", x.f, x.s.f, x.s.s);
	for(int a=0; a<n; a++)
		solve_min(a);
	printf("%d\n", ans_min);
	sort(vec_min.begin(), vec_min.end());
	for(auto x:vec_min)
		printf("%d %d %d\n", x.f, x.s.f, x.s.s);
	return 0;
}