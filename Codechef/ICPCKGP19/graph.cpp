#include<bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

vector < pii > edges;

pii proto1 = { }
pii proto2 = { {1 7}
{1 8}
{1 9}
{2 7}
{2 8}
{2 9}
{3 6}
{3 7}
{3 8}
{4 6}
{4 9}
{4 10}
{5 10}
{5 6} };
int last = 0, M, cnt=0;
void outp
{
	cout << last << 
}
int main()
{
	int k;
	cin >> k;
	for(int i = 1; i <= M; i++)
	{
		edges.pb({proto1[i].F, proto1[i].S});
		cnt++;
	}
	last = M;
	if(k==1)
	{
		edges.pb({x, last + x});
		for(int i = 1; i <= M; i++)
		{
			edges.pb({last + proto1[i].F, last + proto1[i].S});
		}
		outp();
		return 0;
	}
	for(int i = 1; i <= k-1; i++)
	{
		edges.pb({x, last + 4});
		for(int j = 0; j < 11; j++)
		{
			edges.pb({last + proto2[j].F, last + proto2[j].S});
		}
		if(i!=k-1)
		{
			edges.pb({last + 8, last + 12});
		}
		last+=8;
	}
	edges.pb({last, last + x});
	for(int i = 1; i <= M; i++)
	{
		edges.pb({last + proto1[i].F, last + proto1[i].S});
	}
	outp();
}

/*
1 4
1 5
1 6
2 5
2 6
2 7
3 4
3 5
3 7