int spf[N],;
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
vector< pii > primefactorize(int x)
{ 
	vector< pii > ret;
	while(x>1)
	{
		int cspf=spf[x], c=0;
		while(spf[x]==cspf)
		{
			x/=cspf;
			c++;
		}
		ret.pb(mp(cspf, c));
	}
}
