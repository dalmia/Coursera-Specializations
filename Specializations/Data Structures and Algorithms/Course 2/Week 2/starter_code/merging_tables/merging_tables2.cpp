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
ll row[maxn];
ll p[maxn];
ll maxv=0;

ll find(ll i){
    if(row[i]!=0 || p[i]==i) return i;
    p[i]=find(p[i]);
    return p[i];
}

ll solve(ll d, ll s){
    d=find(d);
    s=find(s);
    if(d == s) return maxv;
    row[d] += row[s];
    row[s]=0;
    p[s]=d;
    if(row[d]>maxv) maxv=row[d];
    return maxv;

}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n,d,s;
    cin>>n>>m;
    rep(i, n){
        cin>>row[i];
        p[i]=i;
        if(row[i]>maxv) maxv=row[i];
    }
    rep(i, m){
        cin>>d>>s;
        cout<<solve(d-1,s-1)<<endl;
    }
}
