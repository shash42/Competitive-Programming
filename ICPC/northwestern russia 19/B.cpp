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
 
const int N=5e4+8000, toe9 = 2e9;
const int MOD=1e9+7;
const lint INF=1e18;
 
typedef unsigned long long ull;
typedef long long ll; 

lint _add(lint x, lint y)
{
    lint ret=x+y;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}
 
lint _mult(lint x, lint y)
{
    x%=MOD;
    y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

vi ans;
int GetCeilIndex(int arr[], vector<int>& T, int l, int r,
                 int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
 
int LongestIncreasingSubsequence(int arr[], int n)
{
    // Add boundary case, when array n is zero
    // Depend on smart pointers
 
    vector<int> tailIndices(n, 0); // Initialized with 0
    vector<int> prevIndices(n, -1); // initialized with -1
 
    int len = 1; // it will always point to empty location
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[tailIndices[0]]) {
            // new smallest value
            tailIndices[0] = i;
        }
        else if (arr[i] > arr[tailIndices[len - 1]]) {
            // arr[i] wants to extend largest subsequence
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;
        }
        else {
            // arr[i] wants to be a potential condidate of
            // future subsequence
            // It will replace ceil value in tailIndices
            int pos = GetCeilIndex(arr, tailIndices, -1,
                                   len - 1, arr[i]);
 
            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }
    // cout << "LIS of given input" << endl;
    for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i]){
        ans.pb(arr[i]);
    }
    //cout << mx << endl;
  //  cout << endl;
 
    return len;
}
 
int n, arr2[2*N];
pair<ld, int> arr[2*N], arrr[2*N];
 
const int k = 35400;
int main()
{
    ind(n);
    for(int i = 1; i <= N; i++)
    {
        arr[i]=mp(sin(i), i);
    }
    sort(arr+1, arr+N+1);
    int curr = -k*N;
    for(int i = 1; i <= N; i++)
    {
        //if(i<=100) cout << arr[i].f << endl;
        arr[i].s+=curr;
        curr+=k;
        arrr[i]=arr[i];
    }
    sort(arrr+1, arrr+N+1);
    int cnt=0;
    for(int i = 1; i <= N; i++)
    {
        if(i<=100) cout << arrr[i].f;
        if(arrr[i].s!=arr[i].s) cnt++;
        arr2[i]=arrr[i].s;
        //if(i<=100) cout << arr2[i] << endl;
    }
    //cout << cnt << endl;
    int x = LongestIncreasingSubsequence(arr2, n+1);
    //cout << ans.size() << endl;
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}