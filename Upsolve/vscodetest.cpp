#include<bits/stdc++.h>

using namespace std;

const int mod=1e9+7, N=5e4+4, K=21, B=225, Q=2e5+5;
int pref[N][K], suff[N][K], inblock[B][K][K], n, k, arr[N], q, nb, dp[B][K][K];
struct query
{
    int l, r, idx;
} qrys[Q];
struct qsrt
{
    bool operator()(const query &a, const query &b)
    {
        return a.l < b.l;
    }
};
int block(int x)
{
    return x/B;
}
void setpref()
{
    for(int i = 0; i < n; i++)
    {
        if(i%B==0) continue;
        for(int j = 0; j < k; j++)
        {
            if(arr[i]!=j)
            {
                pref[i][j] = pref[i-1][j]; 
                continue;
            }
            for(int kk = 0; kk <= j; kk++)
            {
                pref[i][j]+=pref[i-1][kk];
                pref[i][j]%=mod;
            }
        }
    }
}
void setsuff()
{
    for(int i = n-1; i >= 0; i--)
    {
        if(i%B==B-1) continue;
        for(int j = 0; j < k; j++)
        {
            if(arr[i]!=j)
            {
                suff[i][j] = suff[i+1][j];
                continue;
            }
            for(int kk = j; kk < k; k++)
            {
                suff[i][j]+=suff[i+1][kk] 
                suff[i][j]%=mod;
            }
        }
    }
}
void makein()
{
    for(int i = 0; i < nb; i++)
    {
        for(int ks = 0; ks < k; ks++)
        {
            for(int ke = ks; ke < k; ke++)
            {
                int last = 0;
                for(int j = B*i; j < min(n, B*(i+1); j++))
                {
                    npref[j][ks]= (arr[j]==ks);
                }
                for(int j = B*i+1; j < min(n, B*(i+1); j++))
                {
                    for(int kk = ks; kk <= ke; kk++)
                    {
                        npref[j][kk] = npref[j][kk]
                    }
                }
            }
        }
    }
}
void process()
{
    for(int i = 0; i < q; i++)
    {
        if(i==0 || block(qrys[i].l) != block(qrys[i-1].l)) initdp(block(qrys[i].l) + 1);
        if(block(qrys[i].l) == block(qrys[i].r))
        {
            ans[qrys[i].idx] = solvesmall(qrys[i].l, qrys[i].r);
        }
        else
        {
            ans[qrys[i].idx] = solvebig(qrys[i].l, qrys[i].r);
        }
    }  
}
void resetdp()
{
    for(int i = 0; i < nb; i++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int kk = 0; kk < k; kk++)
            {
                dp[i][j][kk]=0;
            }
        }
    }
}
void initdp(int st)
{
    resetdp();
    for(int i = st; )
}
int main()
{
    cin >> n >> k;
    nb = n/B + (n%B!=0);
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i+=B)
    {
        for(int j = 0; j < k; j++)
        {
            pref[i][j] = (arr[i]==j);
            if(i!=0) suff[i-1][j] = (arr[i-1]==j)
        }
    }
    setpref();
    setsuff();
    for(int i = 0; i < q; i++)
    {
        cin >> qrys[i].l >> qrys[i].r;
        qrys[i].idx=i;
    }
    makein();
    sort(qrys, qrys+q, qsrt());
    process(); 
}