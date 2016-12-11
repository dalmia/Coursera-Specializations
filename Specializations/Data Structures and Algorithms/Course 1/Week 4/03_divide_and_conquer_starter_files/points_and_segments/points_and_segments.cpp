#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

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
const ll maxn = (ll) 1e5+9;
const ll mod = (ll) 1e9+7;

//ll a[maxn];
//ll dp[1024][1024];
std::vector<pair<ll, ll> > pts;
ll pt[maxn];
map<int, std::vector<int> > mapping;

bool comp(pair<ll, ll> l, pair<ll, ll> r){
    if(l.first != r.first) return l.first<r.first;
    else return l.second<r.second;
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n;
    cin>>n>>m;
    rep(i, n){
        cin>>j>>k;
        pts.pb(mp(j, 0)); pts.pb(mp(k, 2));
    }
    rep(i, m){
        cin>>j;
        pts.pb(mp(j,1));
        mapping[j].pb(i);
    }
    sort(pts.begin(), pts.end(), comp);

    k=0;
    j=0;
    rep(i, pts.size()){
        if(pts[i].second == 0) k++;
        else if(pts[i].second == 2) k--;
        else{
            std::vector<int> in = mapping[pts[i].first];
            for (size_t j = 0; j < in.size(); j++) {
                pt[in[j]] = k;
            }
        }
    }

    for (size_t i = 0; i < m; i++) {
        cout<<pt[i]<<' ';
    }
}
