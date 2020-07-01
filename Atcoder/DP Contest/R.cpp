#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N=52, MOD=1e9+7;
int n, k;

struct Matrix
{
    vector< vector<int> > mat;
    int rows;
    Matrix(vector< vector<int> > val): mat(val), rows(val.size()){}
    Matrix make_ID(int n)
    {
        vector< vector<int> > ID(n, vector<int> (n, 0));
        for(int a=0; a<n; a++)
            ID[a][a]=1;
        return ID;
    }
    Matrix operator*(const Matrix &other) const
    {
        int n=other.rows;
        vector<vector<int> >ret(n, vector<int>(n, 0));
        for(int a=0; a<n; a++)
            for(int b=0; b<n; b++)
                for(int c=0; c<n; c++)
                    ret[a][b]=(ret[a][b]+1LL*mat[a][c]*other.mat[c][b])%MOD;
        return Matrix(ret);
    }

};

Matrix mat_expo(Matrix m, int power)
{
    if(power==1)
        return m;
    Matrix ret=mat_expo(m, power/2);
    ret=ret*ret;
    if(power%2)
        ret=ret*m;
    return ret;
}

vector< vector<int> > adj;
vector<int> emp;
signed main()
{

	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		adj.pb(emp);
		for(int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			adj[i].pb(x);
		}
	}
	Matrix p(adj);
	Matrix fin = mat_expo(p, k);
	int ans=0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			ans+=fin.mat[i][j];
			ans%=MOD;
		}
	}
	cout << ans;
}