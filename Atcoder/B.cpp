#include<bits/stdc++.h>
#define lint long long

using namespace std;

const int N=1e5+5;
int n, m, v, p, a[N], lft[N];
bool check(int x)
{
	lint tot = ((lint) m)*v;
	int curr=a[x]+m;
	int ov=0;
	int ptrr=n+1; //first number still bigger than curr
	for(int i = x+1; i <= n; i++)
	{
		if(a[i]>curr)
		{
			ptrr=i;
			break;
		}
	}
	tot-=(n-ptrr+1)*((lint) m);
	int pos=n-ptrr+2;
	int ptrl=n+1; //first number bigger than x
	for(int i = 1; i < ptrr; i++)
	{
		if(a[i]>a[x])
		{
			ptrl=i;
			break;
		}
	}
	tot-=(ptrl-1LL)*((lint) m);
	//[ptrl, ptrr)
	//cout << ptrl << " " << ptrr << " - " << tot << endl;
	for(int i = ptrl; i < ptrr; i++)
	{
		lft[i]=m;
	}
	for(int i = ptrl; i < ptrr; i++)
	{
		lft[i]-=(curr-a[i]);
		tot-=(curr-a[i]);
	}
	for(int i = ptrr-1; i >= ptrl; i--)
	{
		if(tot<=0) break;
		tot-=lft[i];
		ov++;
	}
	if(ov+pos<=p) return true;
	else return false;
}
int main()
{
	cin >> n >> m >> v >> p;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int lo = 1, hi = n-p+1;
	while(true)
	{
		if(hi-lo<=1)
		{
			bool chk = check(lo);
			if(chk)
			{
				cout << n-lo+1;
				return 0;
			}
			cout << n-hi+1;
			return 0;
		}
		int mid=(lo+hi)/2;
		bool chk = check(mid);
		if(chk)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	//cout << check(3) << endl;
}