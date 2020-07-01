#include<bits/stdc++.h>

using namespace std;
const int N=1049000;
int mask[N], l;
bool hasocc[20];
string S;
int main()
{
	cin >> S;
	l=S.length();
	int ptr=0;
	while(ptr<l)
	{
		for(int i = 0; i < 20; i++) hasocc[i]=false;
		while(ptr<l)
		{
			if(hasocc[S[ptr]-'a'])
			{
				break;
			}
			hasocc[S[ptr]-'a']=true;
			ptr++;
		}
		int mskv=0;
		for(int i = 0; i < 20; i++)
		{
			if(hasocc[i]) mskv+=(1<<i);
		}
		mask[mskv]=1;
	}
	for(int i = 0; i < l; i++)
	{
		for(int j = 20; j >= 10; j++)
		{

		}
	}
}