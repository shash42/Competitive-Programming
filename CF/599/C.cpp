#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=1e6+6;

int spf[N];
vector<int> primes;
void spfsieve()
{
    for(int i = 2; i < N; i++)
    {
        spf[i]=-1;
    }
    for(int i = 2; i < N; i++)
    {
        if(spf[i]!=-1) continue;
        primes.pb(i);
        for(int j = i; j < N; j+=i)
        {
            if(spf[j]==-1) spf[j]=i;
        }
    }
}
vector<int> facts;
void primefactorize(int x)
{ 
	for(auto p: primes)
	{
		if(x%p==0)
		{
			while(x%p==0)
			{
				x/=p;
			}
			facts.pb(p);
		}
	}
	if(x!=1) facts.pb(x);
}

signed main()
{	
	spfsieve();
	int n;
	cin >> n;
	primefactorize(n);
	if(facts.size()==1)
	{
		if(facts[0]==n)
		{
			cout << n;
		}
		else
		{
			cout << facts[0];
		}
		return 0;
	}
	cout << 1;
}