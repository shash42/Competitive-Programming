#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std ;
using namespace __gnu_pbds;

template <typename T> // *s.find_by_order(0), s.order_of_key(2) ;
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define reMin(a, b) a = min(a, b)
#define reMax(a, b) a = max(a, b)

#define lint long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define f first
#define s second

typedef vector < int > vi ;
typedef pair < int, int > pii ;

const int N = 1000 + 2 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;

char grid[N][N], grid2[N][N];
int n, m ;

void fillGrid(int x1, int y1, int x2, int y2, char c, char grid[N][N])
{
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; ++j)
        {
            if(grid[i][j] == '.')
                grid[i][j] = tolower(c) ;
        }
}

void printGrid(char grid[N][N])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            assert(grid[i][j]!='.');
            cout << grid[i][j] ;
        }
        cout << endl ;
    }
    cout << endl ;
}

void maximize(int x, int y, char ch, char grid[N][N])
{
    int bestL[N], bestR[N] ; // Stores best left column and right col for each row respectively
    for(int row = 0; row < n; row++)
    {
        int col = y - 1;
        while(col >= 0 and grid[row][col] == '.')
            col-- ;
        bestL[row] = col + 1 ;

        col = y + 1 ;
        while(col < m and grid[row][col] == '.')
            col++ ;
        bestR[row] = col - 1 ;

        if(row != x and grid[row][y] != '.') bestL[row] = m+1, bestR[row] = -1 ;
        // cout << row << " : " << bestL[row] << " : " << bestR[row] << endl ;
    }

    int x1 = x, y1 = y, x2 = x, y2 = y ;
    int bestArea = 1 ;

    for(int r1 = x; r1 >= 0; r1--)
    {
        int leftCol = bestL[r1], rightCol = bestR[r1] ; int i = r1 ;

        while(i <= x)
        {
            reMax(leftCol, bestL[i]);
            reMin(rightCol, bestR[i]);
            i++ ;
        }

        for(int r2 = x; r2 < n; r2++)
        {
            reMax(leftCol, bestL[r2]);
            reMin(rightCol, bestR[r2]);

            int area = max(0, (rightCol - leftCol + 1) * (r2 - r1 + 1));
            if(area > bestArea)
            {
                x1 = r1 ; x2 = r2 ;
                y1 = leftCol ; y2 = rightCol ;
                bestArea = area ;
            }
        }

    }
    fillGrid(x1, y1, x2, y2, ch, grid);
    //printGrid();
}
void makegrid(int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            grid[i][j]='.';
        }
    }
    for(int i = 0; i < 20; i++)
    {
        int lol1=rand()%x, lol2=rand()%y;
        grid[lol1][lol2]='A'+i;
    }
}
bool checkGrid(int x, int y)
{
    bool flag=false;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            if(grid2[i][j]=='.')
            {
                flag=true;
                break;
            }
        }
    }
/*    if(!flag) return;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }*/
    return !flag;
}
int main()
{
    vector< pii > nxts;
    srand(time(NULL));
    n = 10, m = 10;
    fastio; cin >> n >> m ;
 //   makegrid(n, m);
    int xA = 0, yA = 0 ;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> grid[i][j] ;
        if(grid[i][j] == 'A')
            xA = i, yA = j ;
        else if(grid[i][j]!='.')
        {
            nxts.pb(mp(i, j));
        }
    }
    maximize(xA, yA, 'A', grid);
    bool ret = false;
    while(!ret)
    {
        random_shuffle(nxts.begin(), nxts.end());
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                grid2[i][j]=grid[i][j];
            }
        }
        for(auto v: nxts)
        {
            maximize(v.f, v.s, grid2[v.f][v.s], grid2);
        }
        ret = checkGrid(n, m);
        if(ret)
        {
            printGrid(grid2);
            return 0;
        }
    }
}
/*
6 8
......X.
.F......
...A....
........
.....P..
..L.....
*/