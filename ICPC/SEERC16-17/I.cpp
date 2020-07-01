#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N=3e3+3;
vector<int> prog, sp;
struct st
{
	int idx, a, b, g, idx2;
} stud[N];
struct studsrt
{
	bool operator()(const st &s1, const st &s2)
	{
		return s1.a > s2.a;
	}
};
struct pq1srt
{
	bool operator()(const st &s1, const st &s2)
	{
		return s1.b < s2.b;
	}
};
struct pq2srt
{
	bool operator()(const st &s1, const st &s2)
	{
		return s1.b - s1.a < s2.b - s2.a;
	}
};
priority_queue< st, vector< st >, pq1srt > pqg0;
priority_queue< st, vector< st >, pq2srt > pqg1;
st infst;
int n, p, s, score, ptr;
int main()
{
	infst.b = -99999;
	infst.a = 0;
	cin >> n >> p >> s;
	ptr=p;
	for(int i = 0; i < n; i++)
	{
		cin >> stud[i].a;
		stud[i].idx=i+1;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> stud[i].b;
	}
	sort(stud, stud+n, studsrt());
	for(int i = 0; i < p; i++)
	{
		score+=stud[i].a;
		stud[i].g=1;
	}
	for(int i = 0; i < n; i++)
	{
		stud[i].idx2=i+1;
		if(stud[i].g==0) pqg0.push(stud[i]);
		else pqg1.push(stud[i]); 
	}
	for(int cnts = 0; cnts < s; cnts++)
	{
		st g0 = infst, g1 = infst;
		while(pqg0.size() && stud[pqg0.top().idx2-1].g>=1)
		{
			pqg0.pop();
		}
		while(pqg1.size() && stud[pqg1.top().idx2-1].g==2)
		{
			pqg1.pop();
		}
		if(pqg0.size()) g0 = pqg0.top();
		if(pqg1.size()) g1 = pqg1.top();
		if(g0.b > g1.b - g1.a + stud[ptr].a)
		{
			//cout << "0: " << g0.idx << endl;
			pqg0.pop();
			stud[g0.idx2-1].g = 2;
			while(stud[ptr].g!=0) ptr++;
			score+=g0.b;
		}
		else
		{
		//	cout << "1: " << g1.idx << endl;
			pqg1.pop();
			stud[g1.idx2-1].g = 2;
			stud[ptr].g = 1;
			pqg1.push(stud[ptr]);
			score+=g1.b - g1.a + stud[ptr].a;
			while(stud[ptr].g!=0) ptr++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(stud[i].g==1) prog.pb(stud[i].idx);
		else if(stud[i].g==2) sp.pb(stud[i].idx);
	}
	cout << score << endl;
	for(auto v: prog) cout << v << " ";
		cout << endl;
	for(auto v: sp) cout << v << " ";
}