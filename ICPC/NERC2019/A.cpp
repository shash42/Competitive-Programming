#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5, M=5e4+4;
int n, m, currpos[N], mn[N], mx[N], likes[M], arr[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		arr[i]=currpos[i]=i;
		mn[i]=mx[i]=i;
	}
	for(int i = 1; i <= m; i++)
	{
		int l;
		cin >> l;
		int cpos = currpos[l];
		if(cpos==1) continue;
		currpos[l]--;
		mn[l]=min(mn[l], currpos[l]);
		currpos[arr[cpos-1]]=cpos;
		mx[arr[cpos-1]]=max(mx[arr[cpos-1]], cpos);
		swap(arr[cpos-1], arr[cpos]);
	}
	for(int i = 1; i <= n; i++)
	{
		cout << mn[i] << " " << mx[i] << "\n";
	}
}