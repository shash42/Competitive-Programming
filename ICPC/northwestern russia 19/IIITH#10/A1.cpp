#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define pii pair<int, int>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;

using namespace std;

int n, k;
pii arr[N];
queue<int> q;

struct comp
{
	bool operator()(const pii &a, const pii &b)
	{
		return a.S < b.S;
	}
};
signed main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].F >> arr[i].S;
	}
	sort(arr, arr+n, comp());
	int cntk=0, ans=0;
	for(int i = 0; i < n; i++)
	{
		if(q.size() && q.front()<=arr[i].F)
		{
			cntk--;
			q.pop();
		}
		if(cntk<k)
		{
			q.push(arr[i].S);
			cntk++;
			ans++;
		}
	}
	cout << ans;
	return 0;
}