#include<bits/stdc++.h>

using namespace std;

const int N = 3e5, M = 18, K = 502;
int k, mat[K][K], cnt=1;
signed main()
{
    cin >> k;
    int mx = (1<<M)-1;
    cout << 3 << " " << 2 << endl;
    cout << mx << " " << mx-k << endl;
    cout << mx - (1<<(M-1)) << " " << mx << endl;
    cout << 0 << " " << k << endl;
}