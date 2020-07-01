/FUNCTIONS COPIED FROM GEEKSFORGEEKS

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

const int N=5e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

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

lint n, k, arr[N], idx[N];


// Binary search 
lint GetCeilIndex(lint arr[], vector<lint>& T, lint l, lint r, 
                lint key) 
{ 
    while (r - l > 1) { 
        lint m = l + (r - l) / 2; 
        if (arr[T[m]] >= key) 
            r = m; 
        else
            l = m; 
    } 

    return r; 
} 

void LongestIncreasingSubsequence() 
{ 
    vector<lint> tailIndices(n, 0); 
    vector<lint> prevIndices(n, -1);
    lint len = 1; 
    for (lint i = 1; i < n; i++) 
    { 
        if (arr[i] < arr[tailIndices[0]]) 
            tailIndices[0] = i; 
        else if (arr[i] > arr[tailIndices[len - 1]]) 
        { 
            prevIndices[i] = tailIndices[len - 1]; 
            tailIndices[len++] = i; 
        } 
        else {

            lint pos = GetCeilIndex(arr, tailIndices, -1, len - 1, arr[i]); 
            prevIndices[i] = tailIndices[pos - 1]; 
            tailIndices[pos] = i; 
        } 
    }
    for(lint i=0; i<len; i++)
    {
        if(tailIndices[i]==n-1)
        {
            if(i>=k-1)
            {
                printf("YES\n");
                vector<lint>indices;
                lint x=n-1;
                while(x>=0)
                {
                    indices.pb(x);
                    x=prevIndices[x];
                }
                printf("%lld ", idx[indices[k-1]]+1);
                for(lint a=k-2; a>=0; a--)
                    printf("%lld ", idx[indices[a]]-idx[indices[a+1]]);
                printf("\n");
                return;
            }
            else
            {
                printf("NO\n");
                return;
            }
        }
    } 
} 

lint arr2[N];

void main2()
{
    inlld(n);
    inlld(k);
    for(lint a=0; a<n; a++)
    {
        lint x;
        inlld(x);
        if(a>0)
            arr[a]=arr[a-1]+x;
        else
            arr[a]=x;
    }
    lint x=0;
    for(lint a=0; a<n; a++)
        if(arr[a]>0)
        {
            idx[x]=a;
            arr2[x++]=arr[a];
        }
    for(lint a=0; a<x; a++)
        arr[a]=arr2[a];
    n=x;
    // for(int a=0; a<n; a++)
    //     printf("%lld ", arr[a]);
    // printf("\n");
    if(n<k)
        printf("NO\n");
    else
        LongestIncreasingSubsequence();
}

int main()
{
    int t;
    ind(t);
    while(t--)
        main2();
    return 0;
}