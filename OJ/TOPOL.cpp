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

int n, a[N], ans[N];
signed main()
{
    Heap hp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        hp.push(-a[i]);
        if(i<2) {
            cout << -1 << endl;
            continue;
        }
        int b[3];
        for(int j = 0; j < 3; j++)
        {
            b[j] = -hp.top();
            hp.pop();
        }
        for(int j = 0; j < 3; j++)
        {
            hp.push(-b[j]);
        }
        lint ans = b[0];
        ans*=b[1];
        ans*=b[2];
        cout << ans << endl;
    }
}