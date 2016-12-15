#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
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
ll pre[maxn];
bool visited[maxn];
set<ll> neg;
void bfs(ll y){
    visited[y]=true;
    queue<ll> q;
    q.push(y);
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        vector<pair<ll, ll> > n=adj[u];
        ll i;
        rep(i, n.size()){
            pair<ll,ll> p=n[i];
            if(!visited[p.first]){
                q.push(p.first);
                visited[p.first]=true;
                neg.insert(p.first);
            }
        }
    }
}
int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,m,l,r,n,u,v,s;
    cin>>n>>m;
    rep(i,m){
        cin>>j>>k>>l;
        adj[j].pb(mp(k,l));

    }
    cin>>s;
    repr(i, 1, n) dist[i]=INT_MAX;
    dist[s]=0;
    pre[s]=s;
    set<ll>::iterator it;

    for(i=1;i<=n;i++){
        for(int u=1;u<=n;u++){
            vector<pair<ll, ll> > p=adj[u];
            rep(j, p.size()){
                pair<ll, ll> nei=p[j];
                if(dist[u]+nei.second<dist[nei.first]){
                    dist[nei.first]=dist[u]+nei.second;
                    pre[nei.first]=u;
                    if(i==n) neg.insert(nei.first);
                }
            }
        }
    }

    for(it=neg.begin(); it!=neg.end(); it++){
        ll x=*it;
        ll i=0;
        while(i<n){
            x=pre[x];
            i++;
        }
        ll y=x;
        neg.insert(y);
        x=pre[x];
        while(y!=x){
            neg.insert(x);
            x=pre[x];
        }
        if(!visited[y]) bfs(y);
    }

    repr(i, 1, n){
        it =neg.find(i);
        if(dist[i]==INT_MAX) cout<<"*"<<endl;
        else if(it!=neg.end()){cout<<"-"<<endl;}
        else cout<<dist[i]<<endl;
    }
}
