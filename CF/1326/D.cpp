#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e6+5, INF=1e9;
using namespace std;
int pi[2*N+5];
string s, t, t1, ans;
void kmp(string t) // To check occurence of T in S , create K = T + # + S, and whenever pi[x] = |T|, it means T occurs at (x - 2*|T|) position in T. 
{
    int n = t.length();
    pi[0] = 0; // pi[j]=length of LONGEST PROPER prefix of substring T[0...j] which also suffix
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1] ;
        while(j > 0 and t[j] != t[i]) j = pi[j-1] ;
        if(t[i] == t[j]) j++ ; pi[i] = j ;
    }
} // BTW: The (shortest) period of a given string T is k if k | n (ie n % k == 0) where k = n - pi[n-1] 
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while(tst--)
    {
        /*s="";
        for(int i = 0; i < N; i++)
        {
            s+='a';
        }*/
        cin >> s;
        int l = 0, r = s.length()-1;
        while(l < r && s[l]==s[r])
        {
            l++;
            r--;
        }
        if(l>r)
        {
            cout << s << endl;
            continue;
        }
        t = "";
        for(int i = l; i <= r; i++)
        {
            t+=s[i];
        }
        t1 = t;
        t1+='#';
        for(int i = t.length()-1; i>=0; i--)
        {
            t1+=t[i];
        }
        //t+#+t.rev
        kmp(t1);
        int lng1 = pi[t1.length()-1];
        t1="";
        for(int i = t.length()-1; i>=0; i--)
        {
            t1 += t[i];
        }
        t1+='#';
        t1+=t; //t.rev + # + t
        kmp(t1);
        int lng2 = pi[t1.length()-1];
        /*cout << l << " - " << r << endl;
        cout << "longs: " << lng1 << " " << lng2 << endl;*/
        ans = "";
        for(int i = 0; i < l; i++)
        {
            ans+=s[i];
        }
        if(lng1>=lng2)
        {
            for(int i = l; i < l+lng1; i++)
            {
                ans+=s[i];
            }
        }
        else
        {
            for(int i = r-lng2+1; i <= r; i++)
            {
                ans+=s[i];
            }
        }
        for(int i = r+1; i < s.length(); i++)
        {
            ans+=s[i];
        }
        cout << ans << endl;
    }
}