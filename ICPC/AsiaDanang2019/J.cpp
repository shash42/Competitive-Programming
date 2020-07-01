#include<bits/stdc++.h>

using namespace std;

const int N=1e4;
int FF(int tmp)
{
	int ret = -1;
	int nonzero=0;
	int one = 0;
	int x = tmp;
	ret+=x%10;
	x/=10;
	nonzero++;
	while(x>0)
	{
		if(x%10)
		{	
			nonzero++;
			if(x%10==1) one=1;
		}
		ret+=x%10;
		x/=10;
	}
	return ret + nonzero - 1 - one;
}
int anss[N];
int main()
{
	int t=N;
	cin >> t;
	while(t--)
	{
	//	if(t==0) break;
		int x;
	//	x=t;
		cin >> x;
		int curr=1, pow=0, s1=0;
		while(curr<=x/10)
		{
			pow++;
			curr*=10;
		}
		s1 = pow*(18 + (pow-1)*10);
		s1/=2;
		int ans = s1;
		if(x<10)
		{
			ans = x-1;
			cout << ans << endl;
		}
		else if(curr==x)
		{
			cout << ans << endl;
		}
		else if(x%curr==0)
		{
			ans += FF(x-1) + 1;
			cout << ans << endl;
		}
		else
		{
			ans += FF(x);
			cout << ans << endl;
		}
		anss[t]=ans;
	}
	/*for(int i = 1; i <= N; i++)
	{
		for(int j = i+1; j <= N; j++)
		{
			if(anss[j]-anss[i]>j-i)
			{
				cout << i << " " << j << " " << anss[i] << " " << anss[j];
				return 0;
			}
		}
	}*/
}