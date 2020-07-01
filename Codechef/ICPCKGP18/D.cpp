#include<bits/stdc++.h>

using namespace std;

const int N=106;
int cnt[N];
int main()
{
	for(int i = 1; i <= N; i++)
	{
		cnt[N%i]++;
	}
	for(int i = 1; i <= N/2; i++)
	{
		cout << i << " " << cnt[i] << endl;
	}
}