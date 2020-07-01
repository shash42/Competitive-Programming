#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
#include <array>
using namespace std;
 
int same(array<int, 4> a, array<int, 4> b){
    int ret = 0;
    if(a == b) ret++;
    if(a == array<int, 4>{b[1], b[2], b[3], b[0]}) ret++;
    if(a == array<int, 4>{b[2], b[3], b[0], b[1]}) ret++;
    if(a == array<int, 4>{b[3], b[0], b[1], b[2]}) ret++;
    return ret;
}
void print(array<int, 4> a)
{
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
}
 
map<array<int, 4>, int> mp;
vector<array<int, 4> > up;
 
int n;
 
const int maxn = 405;
 
int main(){
    cin >> n;
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        array<int, 4> c;
        for(int j = 0;j < 4;j++){
            cin >> c[j];
        }
        for(auto d : up){
            long long ret = 1;
            array<int, 4> w = {d[1], d[0], c[1], c[0]};
            array<int, 4> x = {d[2], d[1], c[0], c[3]};
            array<int, 4> y = {d[0], d[3], c[2], c[1]};
            array<int, 4> z = {d[3], d[2], c[3], c[2]};
            ret *= mp[w] - same(w, d);
            ret *= mp[x] - same(x, w) - same(x, d);
            ret *= mp[y] - same(y, x) - same(y, w) - same(y, d);
            ret *= mp[z] - same(z, y) - same(z, x) - same(z, w) - same(z, d);
            if(ret)
            {
                print(d);
            }
            ans += ret;
        }
        up.push_back(array<int, 4>{c[0], c[1], c[2], c[3]});mp[up.back()]++; 
        up.push_back(array<int, 4>{c[1], c[2], c[3], c[0]});mp[up.back()]++;
        up.push_back(array<int, 4>{c[2], c[3], c[0], c[1]});mp[up.back()]++;
        up.push_back(array<int, 4>{c[3], c[0], c[1], c[2]});mp[up.back()]++;
    }
    cout << ans << endl;
    return 0;
}