#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N=2005;
const double LB=1e-13, UB=1e13;

double precbal(vector< double > num, vector< double > denom)
{
	double curr=1;
	int pn=0, pd=0;
	while(pn<num.size() && pd<denom.size())
	{
		if(curr<UB) curr*=num[pn++];
		else curr/=denom[pd++];
	}
	while(pn<num.size())	curr*=num[pn++];
	while(pd<denom.size())	curr/=denom[pd++];
	return curr;
}
vector< double > num, denom;
int main()
{
	int n, n1, n2, I;
	double P, fav=0, ufav=0;
	cout << setprecision(25);
	cin >> n >> n1 >> n2 >> I >> P;
	int x = min(n1, I-1), y = n2, tot=I-1;
	for(int i = tot; i >= 0; i--)
	{
		for(int j = 1; j <= tot; j++) num.pb(j), denom.pb(100);
		for(int j = 1; j <= i; j++) num.pb(100-P), denom.pb(j);
		for(int j = 1; j <= tot-i; j++) num.pb(P), denom.pb(j);
		double coeff=precbal(num, denom); //Tot choose i * (1-p)^i * p^(tot-i);
		num.clear(); denom.clear();
		if(tot-i>=y) ufav+=coeff;
		else	fav+=coeff;
	}
	cout << fav/(fav+ufav);
}