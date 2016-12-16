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
vector<pair<pair<ll, ll>,double> > e(maxn);
vector<ll> x(maxn), y(maxn);
ll c;
ll p[maxn];
ll ran[maxn];

void ms(ll n){
    ll i;
    repr(i, 1, n){
        p[i]=i;
        ran[i]=0;
    }
}

ll find(ll i){
    if(p[i]!=i){
        p[i]=find(p[i]);
    }
    return p[i];
}

ll un(ll fm, ll fn){
    if(ran[fm]<ran[fn]){
        p[fm]=fn;
    }else if(ran[fm]<ran[fn]) p[fn]=fm;
    else{
        p[fm]=fn;
        ran[fn]+=1;
    }
}


bool comp(pair<pair<ll,ll>, double> l,pair<pair<ll,ll>, double>  r){
    return l.second<r.second;
}


int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,m,l,r,n,u,v;
    cin>>n;
    repr(i,1,n){
        cin>>x[i]>>y[i];

    }
    cin>>k;
    repr(i, 1, n){
        repr(j, i+1, n){
            double d=sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j],2));
            e.pb(mp(mp(i,j),d));
        }
    }
    sort(e.begin(), e.end(), comp);
    c=n; i=0;
    ms(n);
    while(c>k){
        pair<pair<ll, ll>, double> pair=e[i++];
        ll ff=find(pair.first.first);
        ll fs=find(pair.first.second);
        if(ff!=fs){
            c--;
            un(ff,fs);
        }
    }
    repr(i,1,n){
        find(i);
    }
    double val=DBL_MAX;
    repr(i, 1, n){
        repr(j, i+1, n){
            if(p[i]!=p[j]){
                double d=sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j],2));
                val = MIN(d, val);
            }
        }
    }
    cout<<setprecision(10)<<val<<endl;
}
