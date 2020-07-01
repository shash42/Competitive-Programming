#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;


struct SuffixAutomaton {
  vector<map<char,int>> edges; // edges[i]  : the labeled edges from node i
  vector<int> link;            // link[i]   : the parent of i
  vector<int> length;          // length[i] : the length of the longest string in the ith class
  int last;                    // the index of the equivalence class of the whole string

  SuffixAutomaton(string s) {
    // add the initial node
    edges.push_back(map<char,int>());
    link.push_back(-1);
    length.push_back(0);
    last = 0;

    for(int i=0;i<s.size();i++) {
      // construct r
      edges.push_back(map<char,int>());
      length.push_back(i+1);
      link.push_back(0);
      int r = edges.size() - 1;

      // add edges to r and find p with link to q
      int p = last;
      while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
        edges[p][s[i]] = r;
        p = link[p];
      }
      if(p != -1) {
        int q = edges[p][s[i]];
        if(length[p] + 1 == length[q]) {
          // we do not have to split q, just set the correct suffix link
          link[r] = q;
        } else {
          // we have to split, add q'
          edges.push_back(edges[q]); // copy edges of q
          length.push_back(length[p] + 1);
          link.push_back(link[q]); // copy parent of q
          int qq = edges.size()-1;
          // add qq as the new parent of q and r
          link[q] = qq;
          link[r] = qq;
          // move short classes pointing to q to point to q'
          while(p >= 0 && edges[p][s[i]] == q) {
            edges[p][s[i]] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
  }
};



string t ; 
int tc ;
string s ;
int freq[30] ;

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0); 
    cin >> t ; 
    SuffixAutomaton a(t); int length = t.length() ;
    memset(freq, 0, sizeof(freq)); 
    for(int i = 0; i < length; i++)
        freq[t[i] - 'A']++ ;

    /*
    bool fail = false;
    int n = 0;
    for(int i=0;i<w.size();i++) {
        if(a.edges[n].find(w[i]) == a.edges[n].end()) {
            fail = true;
            break;
        }
        n = a.edges[n][w[i]];
    }
    if(!fail) cout << w << " is a substring of " << s << "\n";
    */

    cin >> tc ;
    while(tc--)
    {
        cin >> s ; int last = 0 ; int len = s.length() ; bool pos = 1 ;

        for(int i = 0; i < len; i++) if(freq[s[i] - 'A'] == 0) pos = 0 ;
        if(!pos)
        {
            cout << -1 << endl  ;
            continue ; 
        }

        int n = 0; int cnt = 0 ;
        for(int i=0;i<len;i++) {
            if(a.edges[n].find(s[i]) == a.edges[n].end()) {
                // cout << (i - last + 1) << " " ;
                cnt++ ; 
                n = 0 ;
                last = i ;
                i-- ;
                continue ; 
            }
            n = a.edges[n][s[i]];
        }
        cout << (cnt + 1) << endl ; 
    }
}

/*
SANTIAGO
3
TITA
SANTIAGO
NAS

MONTEVIDEO
4
DEMONIO
MONTE
EDIT
WON
*/

/*


struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 200000;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
*/