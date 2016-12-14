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
vector<pair<ll, pair<ll,ll> > > v;
void inorder(vector<ll> &r, ll i){
    if(v[i].second.first!=-1){
        inorder(r,v[i].second.first);
    }
    r.pb(v[i].first);
    if(v[i].second.second!=-1){
        inorder(r,v[i].second.second);
    }
    return;
}
void preorder(vector<ll> &r, ll i){
    r.pb(v[i].first);
    if(v[i].second.first!=-1){
        preorder(r,v[i].second.first);
    }
    if(v[i].second.second!=-1){
        preorder(r,v[i].second.second);
    }
    return;
}
void postorder(vector<ll> &r, ll i){
    if(v[i].second.first!=-1){
        postorder(r,v[i].second.first);
    }
    if(v[i].second.second!=-1){
        postorder(r,v[i].second.second);
    }
    r.pb(v[i].first);
    return;
}
int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n;
    cin>>n;
    rep(i, n){
        cin>>j>>k>>l;
        v.pb(mp(j, mp(k,l)));
    }
    vector<ll> in,pr,po;
    inorder(in, 0);
    postorder(po, 0);
    preorder(pr, 0);
    rep(i,n){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    rep(i,n){
        cout<<pr[i]<<" ";
    }
    cout<<endl;
    rep(i,n){
        cout<<po[i]<<" ";
    }
    cout<<endl;
}
