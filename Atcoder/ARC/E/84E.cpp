#include<bits/stdc++.h>

using namespace std;

const int N=3e5+5;
int arr[N];
int main()
{
	int n, k;
	cin >> k >> n;
	if(k%2==0)
	{
		arr[0]=k/2;
		for(int i = 1; i < n; i++) arr[i]=k;
		for(int i = 0; i < n; i++) cout << arr[i] << " ";
		return 0;
	}
	for(int i = 0; i < n; i++) arr[i]=(k+1)/2;
	int tkdwn = n/2;
	int pos=n-1;
	while(tkdwn--)
	{
		while(arr[pos]==0)		pos--;
		arr[pos]--;
		if(arr[pos]==0) continue;
		for(int i = pos+1; i < n; i++)		arr[i]=k;
		pos=n-1;
	}
	for(int i = 0; i < n; i++)
	{
		if(arr[i]==0) break;
		cout << arr[i] << " ";
	}
}