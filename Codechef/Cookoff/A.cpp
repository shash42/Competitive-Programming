#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define debug(a) cout << a
#define debug(a, b) cout << a << " " << b << endl
#define debug(a, b, c) cout << a << " - " << b << " " << c << endl
#define debug(a, b, c, d) cout << a << " " << b << " - " << c << " " << d << endl
#define debug(a, b, c, d, e) cout << a << " " << b << " - " << c << " " << d << " " << e << endl

using namespace std;
const int N=1e5+5, dc=1e15;
int t, n, arr[N];
string s;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while(t--)
	{
		int fnum=-1, lnum=-1;
		bool ans=true;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if(arr[i]!=-1 && fnum==-1)
			{
				fnum=i;
			}
			if(arr[i]!=-1) lnum=i;
		}
		cin >> s;
		if(fnum==-1)
		{
			cout << "YES\n";
			continue;
		}
		int ptr=fnum, cnt=arr[fnum];
		while(s[ptr-1]!='>' && ptr>0)
		{
			if(s[ptr]=='=')
			{
				ptr--;
				continue;
			}
			cnt--;
			if(cnt<0)
			{
				cout << "NO\n";
				ans=false;
				break;
			}
			ptr--;
		}
		ptr=lnum, cnt=arr[lnum];
		while(s[ptr]!='<' && ptr<n)
		{
			if(s[ptr]=='=')
			{
				ptr++;
				continue;
			}
			cnt--;
			if(cnt<0)
			{
				cout << "NO\n";
				ans=false;
				break;;	
			}
			ptr++;
		}
		if(!ans)
		{
			continue;
		}
		ptr=fnum;
		int curr=0;
		while(ptr<=lnum)
		{
			if(arr[ptr]==-1)
			{
				int lsgn=0, x=0;
				bool flag=false;
				if(s[ptr-1]=='>') lsgn=-1;
				if(s[ptr-1]=='<') lsgn=1;
				//cout << lsgn << endl;
				while(arr[ptr]==-1)
				{
					if(flag)
					{
						ptr++;
						continue;
					}
					if((lsgn==-1 && s[ptr-1]=='<') || (lsgn==1 && s[ptr-1]=='>'))
					{
						ptr++;
						flag=true;
						continue;
					}
					if(lsgn==0 && s[ptr-1]!='=')
					{
						if(s[ptr-1]=='>') lsgn=-1;
						else lsgn=1;
					}
					if(s[ptr-1]=='>') x--;
					else if(s[ptr-1]=='<') x++; 
					ptr++;
				}
				if(!flag)
				{
					if(!((lsgn==-1 && s[ptr-1]=='<') || (lsgn==1 && s[ptr-1]=='>')))
					{
						if(s[ptr-1]=='>') x--;
						else if(s[ptr-1]=='<') x++;
						if(lsgn==-1)
						{
							if(arr[ptr]>curr+x)
							{
								cout << "NO\n";
								ans=false;
								break;
							}
						}
						else if(lsgn==1)
						{
							if(arr[ptr]<curr+x)
							{
								cout << "NO\n";
								ans=0;
								break;
							}
						}
						else if(lsgn==0)
						{
							if(x<0 && arr[ptr]>=curr)
							{
								cout << "NO\n";
								ans=0;
								break;
							}
							else if(x>0 && arr[ptr]<=curr)
							{
								cout<< "NO\n";
								ans=0;
								break;
							}
							else if(x==0 && arr[ptr]!=curr)
							{
								cout << "NO\n";
								ans=0;
								break;
							}
						}
					}
				}
			}
			curr=arr[ptr];
			ptr++;
		}
		if(ans)
		{
			cout << "YES\n";
		}
	}
}