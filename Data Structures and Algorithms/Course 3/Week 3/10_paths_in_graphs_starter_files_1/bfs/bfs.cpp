#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

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
ll dist[maxn];

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,m,l,r,n,u,v;
    cin>>n>>m;
    rep(i, m){
        cin>>j>>k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    cin>>u>>v;
    repr(i, 1, n) dist[i]=-1;
    dist[u]=0;
    queue<ll> q;
    q.push(u);
    while(!q.empty()){
        r = q.front();
        q.pop();
        vector<ll> t=graph[r];
        rep(i, t.size()){
            if(dist[t[i]] == -1){
                q.push(t[i]);
                dist[t[i]]=dist[r]+1;
            }
        }
    }
    cout<<dist[v]<<endl;
}
