#include<bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lint int

using namespace std;

const int N=1e5+5;
int n, m;
vector< string > mat;
queue< pii > q;
vector < int > vis[N];
int MOD;
lint _add(lint x, lint y)
{
    lint ret=x+y;
    while(ret<0)
        ret+=MOD;
    return ret;
}

int main()
{
	cin >> n >> m;
	MOD=m;
	string s;
	mat.pb(s);
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		mat.pb(s);
		for(int j = 0; j < m; j++) vis[i].pb(-1);
	}
	q.push(mp(1, 0));
	vis[1][0]=0;
	while(q.size())
	{
		int ui = q.front().F;
		int uj = q.front().S;
	//	cout << ui << " " << uj << endl;
		int t = vis[ui][uj];
		if(ui==n)
		{
			cout << vis[ui][uj]+1;
			return 0;
		}
		q.pop();
		if(mat[ui][_add(uj, -2)]!='M' && mat[ui][_add(uj, -1)]!='M' && vis[ui][_add(uj, -2)]==-1)
		{
			q.push(mp(ui, _add(uj, -2)));
			vis[ui][_add(uj, -2)]=t+1;
		}
		if(mat[ui][_add(uj, -1)]!='M' && mat[ui][uj]!='M' && vis[ui][_add(uj, -1)]==-1)
		{
			q.push(mp(ui, _add(uj, -1)));
			vis[ui][_add(uj, -1)]=t+1;
		}
		if(mat[ui+1][_add(uj, -1)]!='M' && mat[ui+1][uj]!='M' && vis[ui+1][_add(uj, -1)]==-1)
		{
			q.push(mp(ui+1, _add(uj, -1)));
			vis[ui+1][_add(uj, -1)]=t+1;
		}
		if(ui != 1 && mat[ui-1][_add(uj, -1)]!='M' && mat[ui-1][uj]!='M' && vis[ui-1][_add(uj, -1)]==-1)
		{
			q.push(mp(ui-1, _add(uj, -1)));
			vis[ui-1][_add(uj, -1)]=t+1;
		}
	}
	cout << -1;
}