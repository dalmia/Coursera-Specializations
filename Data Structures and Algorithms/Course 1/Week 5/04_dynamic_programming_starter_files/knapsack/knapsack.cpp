#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define repr(i,j,n) for(i=j;i<=n;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<int> > graph;
const ll maxw = (ll) 1e4+1;
const ll maxn = (ll) 301;

//ll a[maxn];
ll dp[maxw][maxn];

ll func(int *,int,int);

ll solve(int wts[], int n, int in, int W){
    if(W==0 || in<0) return 0;
    if(dp[W][in]>=0) return dp[W][in];
    ll w2=solve(wts,n,in-1,W);
    if(wts[in]>W) return dp[W][in]=w2;
    else return dp[W][in]=MAX(solve(wts,n,in-1,W-wts[in])+wts[in], w2);
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n;
    int W;
    cin>>W>>n;
    int wt[n];
    rep(i, n){
        cin>>wt[i];
    }

    //memset(dp,-1,sizeof(dp));

    rep(i, maxw){
        rep(j, maxn){
            dp[i][j]=-1;
        }
    }
/*
    repr(i,0,W)if(i>=wt[0])dp[i][0]=wt[0];

    for(i=1;i<n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(j<wt[i])dp[j][i]=dp[j][i-1];
            else dp[j][i]=MAX(dp[j][i-1],dp[j-wt[i]][i-1]+wt[i]);
        }
    }
*/
    //cout<<dp[W][n-1]<<endl;
    cout<<solve(wt, n, n-1, W)<<endl;
    //cout<<func(wt,W,n-1)<<endl;
}

ll func(int wt[], int W,int in)
{
    if(in<0 || W<=0)return 0;
    if(dp[W][in]>=0)return dp[W][in];
    else
    {
        if(W>=wt[in])dp[W][in] = MAX(func(wt,W-wt[in],in-1)+wt[in],func(wt,W,in-1));
        else dp[W][in] = func(wt,W,in-1);
        return dp[W][in];
    }
}
