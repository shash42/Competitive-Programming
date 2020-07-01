#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=2e4;
int arr[N], cntodd=0, n;
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cntodd+=(arr[i]%2 != 0);
	}
	cntodd/=2;
	for(int i = 0; i < n; i++)
	{
		bool neg=(arr[i]<0);
		if(arr[i]%2)
		{
			if(cntodd>0)
			{
				cntodd--;
				arr[i]/=2;
				if(neg) arr[i]--;
			}
			else
			{
				arr[i]/=2;
				if(!neg) arr[i]+=1;
			}
		}
		else arr[i]/=2;
	}
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
}