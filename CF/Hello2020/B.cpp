#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define lint long long

using namespace std;

const int N = 1e5+5, MOD=1e9+7;
int n, l[N], mn;
lint cntasc, cnt;
vector<int> a[N], Ends, begins;
bool hasasc[N];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> l[i];
		mn = MOD;
		for(int j = 0; j < l[i]; j++)
		{
			a[i].pb(0);
			cin >> a[i][j];
			if(a[i][j]>mn && !hasasc[i])
			{
				hasasc[i]=true;
				cntasc++;
			}
			mn=min(mn, a[i][j]);
		}
		if(!hasasc[i])
		{
			begins.pb(a[i][0]);
			Ends.pb(a[i].back());
			//if(a[i].back()==a[i][0]) cnt--; //removing idhar ka double count
		}
	}
	sort(Ends.begin(), Ends.end());
	sort(begins.begin(), begins.end());
	int ptr = 0;
	//cout << begins.size() << " " << Ends.size() << endl;
	for(auto num: Ends)
	{
		while(ptr < begins.size() && begins[ptr] <= num)
		{
			ptr++;
		}
		//cout << num << " " << begins[ptr] << " " << ptr  << endl;
		cnt+=begins.size()-ptr;
		cnt+=cntasc;
	}
	cnt+=1LL*cntasc*n;
	cout << cnt;
}