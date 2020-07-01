#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using namespace std;
const int N=505;
int t, n, logn, arr[N], vis[N], chk[N][N];
vector < vector < int > > V;
vector < int > temp;

void recurse(int l, int r, int half, int sel, int lvl)
{
	if(l>r) return;
	if(sel==1)
	{
		for(int i = l; i <= r; i++)
		{
			V[lvl].pb(arr[i]);
		}
	}
	if(lvl==logn) return;
	int mid = (l+r)/2;
	if(half==0)
	{
		recurse(l, mid, half, 1, lvl+1);
		recurse(mid+1, r, half, 0, lvl+1);
	}
	else
	{
		recurse(l, mid, half, 0, lvl+1);
		recurse(mid+1, r, half, 1, lvl+1);
	}
}
int main()
{
	cin >> t;
	while(t--)
	{
		int ptr=0;
		logn=0;
		while(ptr<V.size()) V[ptr].clear(), ptr++;
		V.clear();
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			arr[i]=i;
		}
		int p2=1;
		while(p2<n)
		{
			p2*=2;
			logn++;
		}
		for(int i = 0; i <= logn; i++)
		{
			V.pb(temp);
		}
		recurse(1, n/2, 0, 1, 1);
		recurse(n/2+1, n, 1, 0, 1);
		for(int i = 1; i <= logn; i++)
		{
			for(int j = 1; j <= n; j++) vis[j]=0;
			for(auto v: V[i])
			{
				vis[v]=1;
			}
			for(int j = 1; j <= n; j++)
			{
				if(!vis[j]) V[i].pb(j);
			}
		}
		cout << logn << endl;
		for(int i = 1; i <= logn; i++)
		{
			for(auto v: V[i])
			{
				cout << v << " ";
			}
			cout << endl;
		}
	/*	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) chk[i][j]=0;
		for(int i = 1; i <= logn; i++)
		{
			for(int j = 0; j < n/2; j++)
			{
				for(int k = n/2; k < n; k++)
				{
					chk[V[i][j]][V[i][k]]=chk[V[i][k]][V[i][j]]=1;
				}
			}
		}
		bool flag=true;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++) cout << chk[i][j] << " ";
			cout << endl;
		}*/
	}
}