#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cfloat>
#include <queue>
#include <math.h>
#include <iomanip>

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
vector<vector<pair<ll, double> > > adj(maxn);
vector<ll> x(maxn), y(maxn);
double dist[maxn];
bool visited[maxn];
ll pre[maxn];

class Comp{
public:
    bool operator()(pair<ll, double> l,pair<ll, double> r){
        return l.second>r.second;
    }
};

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,m,l,r,n,u,v;
    cin>>n;
    repr(i,1,n){
        cin>>x[i]>>y[i];

    }
    repr(i, 1, n){
        repr(j, i+1, n){
            double d=sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j],2));
            adj[i].pb(mp(j,d));
            adj[j].pb(mp(i,d));
        }
    }
    repr(i, 1, n) dist[i]=DBL_MAX;
    dist[1]=0;
    pre[1]=1;
    priority_queue<pair<ll,double>, vector<pair<ll, double> >, Comp > q;
    q.push(mp(1, dist[1]));
    double val=0;
    ll c=0;
    while(c<n && !q.empty()){
        pair<ll, ll> t=q.top();
        q.pop();

        if(!visited[t.first]){
            val+= sqrt(pow(x[t.first]-x[pre[t.first]], 2)+pow(y[t.first]-y[pre[t.first]],2));
            //cout<<t.first<<" "<<prev[t.first]<<endl;
            c++;
            visited[t.first]=true;
            vector<pair<ll, double> > p=adj[t.first];
            rep(i, p.size()){
                pair<ll, double> nei=p[i];
                if(!visited[nei.first]){
                //cout<<t.first<<" "<<nei.first<<" "<<nei.second<<endl;
                    if(nei.second<dist[nei.first]){
                        dist[nei.first]=nei.second;
                        //cout<<"DIST "<<nei.first<<" "<<dist[nei.first]<<endl;
                        pre[nei.first]=t.first;
                        q.push(mp(nei.first, dist[nei.first]));
                    }
                }
            }
        }
    }
    cout<<setprecision(10)<<val<<endl;
}
