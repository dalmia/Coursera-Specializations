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
bool c=true;
vector<vector<ll> > graph(maxn);
pair<bool, int> visited[maxn];
void bfs(ll u){
    visited[u].first=true;
    queue<pair<int, int> > q;
    q.push(mp(u, visited[u].second));
    while(!q.empty()){

        pair<int, int> r = q.front();
        int type=r.second;
        //cout<<"c "<<r.first<<endl;
        q.pop();
        vector<ll> t=graph[r.first];
        ll i;
        rep(i, t.size()){
            if(!visited[t[i]].first){
                q.push(mp(t[i], 1-type));
                visited[t[i]]=mp(true, 1-type);
            }else{
                if(visited[t[i]].second == type){
                    //cout<<"b "<<i<<endl;
                    c=false; return;
                }
            }
        }
    }
}

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
    repr(i, 1, n){ visited[i]=mp(false,0); }
    repr(i, 1, n){
        if(!visited[i].first){
            //cout<<"a "<<i<<endl;
            bfs(i);
        }
    }
    cout<<c<<endl;
}
