#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define lint long long
#define vi vector<int>

using namespace std;

const int N = 502, inf=1e9, mod=1e9+7;
const lint INF = 1e18;

int n, k, found[N];
struct indsrt
{
	bool operator()(const int &a, const int &b)
	{
		return found[a] < found[b];
	}
};
void answer(int x)
{
	cout << "! " << x << endl;
	fflush(stdout);
}
pii query(vi &indices)
{
	cout << "? ";
	for(auto ind : indices)
	{
		cout << ind << " ";
	}
	cout << endl;
	fflush(stdout);
	pii ret;
	cin >> ret.F >> ret.S;
	return ret;
}
void solve1()
{
	for(int i = 0; i <= n; i++)
	{
		found[i]=-1;
	}
	vi indices;
	for(int i = 1; i <= k; i++)
	{
		indices.clear();
		for(int j = 1; j < k+i; j++)
		{
			if(found[j]==-1)
			{
				indices.pb(j);
			}
		}
		pii mth = query(indices);
		found[mth.F]=mth.S;
	}
	//cout << "lol";
	vi pos, val;
	indices.clear();
	for(int i = 1; i <= n; i++)
	{
		if(found[i]!=-1)
		{
			indices.pb(i);
		}
	}
	pii mth = query(indices);
	sort(indices.begin(), indices.end(), indsrt());
	for(int i = 1; i <= k; i++)
	{
		if(mth.F==indices[i-1])
		{
			answer(i);
		}
	}
}
void solve2()
{
	vi indices;
	for(int i = 1; i <= k; i++)
	{
		indices.pb(i);
	}
	pii x = query(indices);
	indices.clear();
	for(int i = 1; i <= k+1; i++)
	{
		if(i!=x.F) indices.pb(i);
	}
	pii kp1 = query(indices);
	bool less = (kp1.S < x.S);
	int chnj=0;
	for(int y = 1; y <= k; y++)
	{
		if(y==x.F) continue;
		indices.clear();
		indices.pb(k+1);
		for(int i = 1; i <= k; i++)
		{
			if(i!=y)
			{
				indices.pb(i);
			}
		}
		pii mth = query(indices);	
		if(mth.S!=x.S) chnj++;
	}
	if(less)
	{
		answer(k-chnj);
	}
	else
	{
		answer(chnj+1);
	}
}
signed main()
{
	cin >> n >> k;
	solve2();
	//if(k<=(n+1)/2) solve1();
	//else solve2();
}