#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pii pair<int, int>
#define ind(x) scanf("%d", &x)

using namespace std;

const int N=105;

int n, m, arr[N][N], ans=1e9;
vector<int>which;

int main()
{
	ind(n);ind(m);
	for(int a=1; a<=m; a++)
		for(int b=1; b<=n; b++)
			ind(arr[a][b]);
	for(int a=1; a<=n-1; a++)
	{
		int sum=0;
		vector<pair<int, int> > here;
		for(int b=1; b<=m; b++)
		{
			sum+=(arr[b][a]-arr[b][n]);
			here.pb({arr[b][a]-arr[b][n], b});
		}
		if(sum>=0)
		{
			printf("0\n");
			return 0;
		}
		sort(here.begin(), here.end());
		int cnt=0;
		vector<int>torem;
		for(int b=0; b<here.size(); b++)
		{
			sum-=here[b].f;
			cnt++;
			torem.pb(here[b].s);
			if(sum>=0)
				break;
		}
		if(cnt<ans)
		{
			ans=cnt;
			which.clear();
			for(int b=0; b<torem.size(); b++)
				which.pb(torem[b]);
		}
	}
	printf("%d\n", ans);
	for(auto x:which)
		printf("%d ", x);
	printf("\n");
	return 0;
}