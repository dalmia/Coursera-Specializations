#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
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
typedef vector<vector<ll> > graph;
const ll maxn = (ll) 1e5+9;
const ll mod = (ll) 1e9+7;

//ll a[maxn];
//ll dp[1024][1024];
vector<vector<pair<ll, ll> > > adj(maxn);
ll dist[maxn];

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,m,l,r,n,u,v;
    cin>>n>>m;
    rep(i,m){
        cin>>j>>k>>l;
        adj[j].pb(mp(k,l));

    }
    repr(i, 1, n) dist[i]=INT_MAX;
    dist[1]=0;
    ll c;
    for(i=1;i<=n;i++){
        c=0;
        for(int u=1;u<=n;u++){
            vector<pair<ll, ll> > p=adj[u];
            rep(j, p.size()){
                pair<ll, ll> nei=p[j];
                if(dist[u]+nei.second<dist[nei.first]){
                    dist[nei.first]=dist[u]+nei.second;
                    c++;
                }
            }
        }
        if(i==n){
            if(c>0) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}
