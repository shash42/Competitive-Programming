#include<iostream>
#include<vector>
#include<utility>
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 1e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, k, l[N], inc[N];
vi lst[N], adj[N], ans;

class Heap
{
public:
    Heap()
    = default;
    vector <int> heap;
    void heapify(int );
    void push(int );
    void pop();
    int top();
    int size();
};
int Heap::size()
{
    return heap.size();
}
void Heap::push(int element)
{
    heap.push_back(element);
    int idx = heap.size() - 1;
    while(heap[(idx-1)/2] > heap[idx])
    {
        int par = (idx-1)/2;
        swap(heap[idx], heap[par]);
        idx = par;
    }
}
void Heap::pop()
{
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapify(0);
}
int Heap::top()
{
    return heap[0];
}
void Heap::heapify(int idx)
{
    int lc = 2*idx+1, rc = 2*idx+2;
    int smol = idx;
    if (lc < heap.size() && heap[lc] < heap[smol]) smol = lc;
    if (rc < heap.size() && heap[rc] < heap[smol]) smol = rc;
    if(smol != idx)
    {
        swap(heap[idx], heap[smol]);
        heapify(smol);
    }
}
signed main()
{
    Heap topoq;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> l[i];
        for (int j = 0; j < l[i]; ++j) {
            int x;
            cin >> x;
            if(x>k || x<1) exit(7);
            lst[i].pb(x);
        }
    }
    for (int i = 1; i < n; ++i) {
        bool done = false;
        for(int j = 0; j < min(l[i-1], l[i]); j++)
        {
            if(lst[i-1][j]!=lst[i][j])
            {
                adj[lst[i-1][j]].pb(lst[i][j]);
                inc[lst[i][j]]++;
                done = true;
                break;
            }
        }
        if(!done)
        {
            if(l[i] < l[i-1])
            {
                cout << -1;
                return 0;
            }
        }
    }
    for(int i = 1; i <= k; i++)
    {
        if(inc[i]==0) topoq.push(i);
    }
    while(topoq.size()!=0)
    {
        int u = topoq.top();
        ans.pb(u);
        topoq.pop();
        for(auto v: adj[u])
        {
            inc[v]--;
            if(inc[v]==0) topoq.push(v);
        }
    }
    if(ans.size()<k){ //checks if there is a cycle
        cout << -1;
        return 0;
    }
    for(auto u: ans)
    {
        cout << u << " ";
    }
}