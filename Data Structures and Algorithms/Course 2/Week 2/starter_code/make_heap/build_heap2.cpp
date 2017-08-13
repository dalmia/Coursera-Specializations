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
typedef vector<vector<int> > graph;
const ll maxn = (ll) 1e5+9;
const ll mod = (ll) 1e9+7;

//ll a[maxn];
//ll dp[1024][1024];
ll v[maxn];

void swap(ll i, ll j){
    ll t=v[i];
    v[i]=v[j];
    v[j]=t;
}

void shiftdown(vector<pair<ll, ll> > &sw, ll i, ll n){
    if(i>=n/2) return;
    ll l=i;
    if(2*i+1<n && v[2*i+1]<v[l]) l=2*i+1;
    if(2*i+2<n && v[2*i+2]<v[l]) l=2*i+2;
    if(l!=i){
        sw.pb(mp(i, l));
        swap(i,l);
        shiftdown(sw, l, n);
    }
    return;
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n,s;
    cin>>n;
    rep(i, n) cin>>v[i];
    vector<pair<ll, ll> > sw;
    for(i=n/2-1; i>=0; i--){
        shiftdown(sw, i, n);
    }
    cout<<sw.size()<<endl;
    rep(i, sw.size()){
        cout<<sw[i].first<<" "<<sw[i].second<<endl;
    }
}
