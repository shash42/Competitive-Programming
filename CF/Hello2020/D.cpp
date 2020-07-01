#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define lint long long

using namespace std;

const int N = 1e5+5, MOD=1e9+7;

struct lect
{
	int sa, ea, sb, eb;
} a[N];
int n;
struct sortbysa
{
	bool operator()(const lect &A, const lect &B)
	{
		return A.sa < B.sa;
	}
};
struct sortbyea
{
	bool operator()(const lect &A, const lect &B)
	{
		return A.ea > B.ea;
	}
};
struct sortbysb
{
	bool operator()(const lect &A, const lect &B)
	{
		return A.sb < B.sb;
	}
};
struct sortbyeb
{
	bool operator()(const lect &A, const lect &B)
	{
		return A.eb < B.eb;
	}
};
priority_queue< lect, vector< lect >, sortbyea > pqa;
set<int> coord;
map<int, int> idx;

set<lect, sortbysb> st;
set<lect, sortbyeb> en;
bool func()
{
	while(pqa.size()) pqa.pop();
	st.clear();
	en.clear();
	sort(a, a+n, sortbysa());	
	for(int i = 0; i < n; i++)
	{
		//cerr << a[i].sa << ": " << endl;
		while(pqa.size() && pqa.top().ea < a[i].sa)
		{
			lect rem = pqa.top();
		//	cerr << "removing: " << rem.ea << endl;
			pqa.pop();
			st.erase(rem);
			en.erase(rem);
		}
		if(st.size())
		{
			auto highst = *(st.rbegin());
		//	cerr << "highest st:" << highst.sb << endl;
			if(a[i].eb < highst.sb)
			{
				return false;
			}
		}	
		if(en.size())
		{
			auto lowen = *(en.begin());
		//	cerr << "lowest en: " << lowen.eb << endl;
			if(a[i].sb > lowen.eb)
			{
				return false;
			}
		}
		st.insert(a[i]);
		en.insert(a[i]);
		pqa.push(a[i]);
	}
	return true;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool flag=true;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].sa >> a[i].ea >> a[i].sb >> a[i].eb;
		coord.insert(a[i].sa);	coord.insert(a[i].ea);
		coord.insert(a[i].sb);	coord.insert(a[i].eb);
	}	
	int ptr = 1;
	for(auto lol: coord)
	{
		idx[lol]=ptr;
		ptr++;
	}
	flag=func();
	if(!flag)
	{
		cout << "NO";
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		swap(a[i].sa, a[i].sb);
		swap(a[i].ea, a[i].eb);
	}
	flag = func();
	if(flag) cout << "YES";
	else cout << "NO";
}	