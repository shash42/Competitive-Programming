#include<bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int n, k;
string s, per = "", chk1 = "", chk2 = "";
void add1()
{
	int it = k-1;
	while(per[it]=='9')
	{
		per[it]='0';
		it--;
	}
	per[it]++;
}
signed main()
{
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i < k; i++)
	{
		per+=s[i];
	}
	chk1 = per;
	for(int i = k; i < n; i++)
	{
		chk1+=per[i%k];
	}
//	cout << chk1 << endl;
	if(chk1.compare(s)>=0)
	{
		cout << n << endl << chk1;
		return 0;
	}
	add1();
	for(int i = 0; i < n; i++)
	{
		chk2+=per[i%k];
	}
	cout << n << endl << chk2;
}