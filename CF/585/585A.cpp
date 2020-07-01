#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;
int a1, a2, k1, k2, n, minans, mxans, n1, n2;
void swap(int &x, int &y)
{
	x+=y;
	y=x-y;
	x-=y;
}
signed main()
{
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if(k2<k1)
	{
		swap(a1, a2);
		swap(k1, k2);
	}
	//cout << a1 << " " << a2 << " " << k1 << " " << k2 << endl;
	n1=n2=n;
	if(n1>=a1*k1)
	{
		n1-=a1*k1;
		mxans+=a1;
	//	cout << n1 << " " << mxans << endl;
		mxans+=n1/k2;
	}
	else
	{
		mxans+=n1/k1;
	}
	int del=a1*(k1-1) + a2*(k2-1);
	minans=max( (int) 0, n-del);
	cout << minans << " " << mxans;

}