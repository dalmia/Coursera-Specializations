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
class Comp{
public:
    bool operator()(pair<ll, ll> l,pair<ll, ll> r){
        return l.second>r.second;
    }
};

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,m,l,r,n,u,v;
    cin>>n>>m;
    rep(i,m){
        cin>>j>>k>>l;
        adj[j].pb(mp(k,l));

    }
    cin>>u>>v;
    repr(i, 1, n) dist[i]=LLONG_MAX;
    dist[u]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll, ll> >, Comp > q;
    q.push(mp(u, dist[u]));
    ll c=0;
    while(c<2*m && !q.empty()){
        pair<ll, ll> t=q.top();
        q.pop();
        vector<pair<ll, ll> > p=adj[t.first];
        rep(i, p.size()){
            c++;
            pair<ll, ll> nei=p[i];
            //cout<<t.first<<" "<<nei.first<<" "<<nei.second<<endl;
            if(dist[nei.first] == -1 || t.second+nei.second<dist[nei.first]){
                dist[nei.first]=t.second+nei.second;
                //cout<<"DIST "<<nei.first<<" "<<dist[nei.first]<<endl;
                q.push(mp(nei.first, dist[nei.first]));
            }
        }
    }
    cout<<(dist[v]==LLONG_MAX? -1:dist[v])<<endl;
}
