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

const int N=1000+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int LN = 17 ;

int grid[N][N] ;
int sparse[N][N][LN] ; 
int n, m ;
int ones[N][N], zeros[N][N] ;
int powers[N] ;

void pre()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < LN; k++)
                sparse[i][j][k] = 0 ; 
    int z = 0 ;
    for(int i = 1; i < N; i++)
    {
        if((1 << (z+1)) <= i) z++ ;
        powers[i] = z ; 
        // if(powers[i] != powers[i-1])
           //  cout << i << " : " << powers[i] << endl ; 
    }
}

void sparseTable()
{
    for(int k = 1; k < LN; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int nxt = i + (1 << (k -1)) ; int nxt2 = i + (1 << k) - 1 ; 
                if(nxt2 >= n or nxt >= n) break ; 
                sparse[i][j][k] = min(sparse[i][j][k-1], sparse[nxt][j][k-1]); 
            }
        }
    }

}

int getVal(int x1, int x2, int y)
{
    if(x2 >= n) return 0;

    int dif = (x2 - x1 + 1) ;
    int high = powers[dif] ; 
    int low = x2 - (1 << high) + 1; 

    if(low >= n or high >= LN) return 0 ; 
    int ans = min(sparse[x1][y][high], sparse[low][y][high]); 
    return ans ; 
}



bool check2(int length)
{
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < m; j++)
        {
            int now = getVal(i, i + length - 1, j); 
            if(now >= length) {
                
                return 1;
            }
        }
    }
    return 0;
}


int main()
{
    pre();
    cin >> n >> m ; char ch ;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> ch ; 
            grid[i][j] = (ch == 'G') ? 1 : 0 ; 
        }
    }

    for(int i = 0; i < n; i++)
    {
        int right0 = m, right1 = m ; 
        for(int j = m-1; j >= 0; j--)
        {
            if(grid[i][j]) ones[i][j] = right0 - j, right1 = j ; 
            else zeros[i][j] = right1 - j, right0 = j ; 
            sparse[i][j][0] = max(zeros[i][j], ones[i][j]); 
           // cout << i << " " << j << " : " << sparse[i][j][0] << endl ; 
        }
    }
    
    sparseTable();

    // cout << sparse[0][0][0] << " " << sparse[1][0][0] << endl ; 
    int low = 1, high = n ; 
    while((high - low) > 1)
    {
        int mid = high + low >> 1 ;
        if(check2(mid)) low = mid ;
        else high = mid - 1 ;
    }
    if(check2(high)) cout << (high * high) ;
    else cout << (low * low) ;
    
	return 0;
}

/*
2 2
GG
GG


5 5
GGGGG
GBBBG
GBBBG
GBBBG
GGGGG
*/

/*


            /*
            if(length == 3) {
                    cout << i << " " << j << endl ;
                    cout << sparse[i][j][0] << " : " << sparse[i][j][1] << endl ; 
                }
                
    for(int i = 0; i < n; i++)
    {
        int l0 = -1, l1 = -1 ; 
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j]) ones[i][j] = min(ones[i][j], j - l0), l1 = j ; 
            else zeros[i][j] = min(zeros[i][j], j - l1), l0 = j  ; 
            vals[i][j] = max(zeros[i][j], ones[i][j]);
            sparse[i][j][0] = vals[i][j] ; 
        }
    }

bool checkEven(int length)
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int bef = length/2 ; 
            int aft = length - bef ; 
        }
    }
    return false ; 
}

bool checkOdd(int length)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            
        }
    }
    return false ; 
}

bool check(int length)
{
    if(length & 1) return checkOdd(length);
    else return checkEven(length);
}
*/