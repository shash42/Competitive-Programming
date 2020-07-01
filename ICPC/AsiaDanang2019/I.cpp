#include<bits/stdc++.h>
#define pb push_back
#define sz(x) (int) x.size()
#define vi vector<int>

using namespace std;

const int N=1e3+3;
int arr[N], n, ans[N];
vi inp;
vi query(vi indices) {
    int cnt = sz(indices);
    
    assert(cnt > 0);

    cout << "ASK " << cnt ;
    for(int x : indices) cout << " " << x;
    cout << endl ;
    cout.flush();

    inp.resize(cnt);
    for(int i = 0; i < cnt; i++)
        cin >> inp[i] ;
    
    fflush(stdin);
    return inp;     
}
int main()
{
    cin >> n;
    fflush(stdin);
    int pow=1, pwcnt=0;
    while(pow<n)
    {
        pwcnt++;
        pow*=2;
    }
    if(pow==n) pwcnt++;
    for(int i = 0; i < pwcnt; i++)
    {
        vi indices;
        for(int j = 1; j <= n; j++)
        {
            if(j&(1<<i)) indices.pb(j);
        }
        vi ret = query(indices);
        for(auto bulb: ret)
        {
            arr[bulb]+=(1<<i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        ans[arr[i]]=i;
    }
    cout << "ANSWER" << " ";
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    fflush(stdout);
}