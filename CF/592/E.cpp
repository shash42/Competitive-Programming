#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;
const int N=1e5+5;
int n, k, arr[N], leftk, currmx, currmn;
signed main()
{
	cin >> n >> k;
	leftk=k;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);
	currmn=arr[0];
	currmx=arr[n-1];
	for(int i = 1; i <= n/2; i++)
	{
		int rt=n-i;
		int lft=i-1;
		int enddiff=arr[rt]-arr[rt-1];
		if(enddiff*i <= leftk)
		{
			leftk-=enddiff*i;
			currmx=arr[rt-1];
			rt--;
		}
		else
		{
			int moving=leftk/i;
			leftk-=moving*i;
			currmx=arr[rt]-moving;
			break;
		}
		if(n%2==0 && i==n/2) break;
		int begdiff=arr[lft+1]-arr[lft];
		if(begdiff*i <= leftk)
		{
			leftk-=begdiff*i;
			currmn=arr[lft+1];
			lft++;
		}
		else
		{
			int moving=leftk/i;
			leftk-=moving*i;
			currmn=arr[lft]+moving;
			break;
		}
	}
	cout << currmx-currmn;
}