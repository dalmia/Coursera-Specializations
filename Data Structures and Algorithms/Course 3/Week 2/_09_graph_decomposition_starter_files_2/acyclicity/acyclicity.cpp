#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
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
const ll maxn = (ll) 1e5+9;
const ll mod = (ll) 1e9+7;

//ll a[maxn];
//ll dp[1024][1024];
vector<vector<ll> > graph(maxn);
bool visited[maxn];
bool marked[maxn];
bool c=false;

void dfs(ll u){
    visited[u]=true;
    marked[u]=true;
    vector<ll> n=graph[u];
    for(int i=0;i<n.size();i++){
        if(marked[n[i]]){
            c = true;
            return;
        }
        else if(!visited[n[i]]) dfs(n[i]);
    }
    marked[u]=false;
}
int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n,u,v;
    cin>>n>>m;
    rep(i, m){
        cin>>j>>k;
        graph[j].pb(k);
    }
    repr(i, 1, n){
        if(!visited[i]){
            //repr(j, 1, n) marked[j]=false;
             dfs(i);
         }
    }
    cout<<c<<endl;
}
