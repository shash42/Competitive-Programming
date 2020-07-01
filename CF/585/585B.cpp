#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;
const int N=2e5+5;
int n, arr[N], pref, cntp, cntn;
signed main()
{
	pref=1;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i]>0) arr[i]=1;
		else arr[i]=-1;
	}
	for(int i = 0; i < n; i++)
	{
		pref*=arr[i];
		if(pref==1) cntp++;
		else cntn++;
	}
	cout << cntp*cntn + cntn << " " << (cntp*(cntp-1))/2 + (cntn*(cntn-1))/2 + cntp; 
}