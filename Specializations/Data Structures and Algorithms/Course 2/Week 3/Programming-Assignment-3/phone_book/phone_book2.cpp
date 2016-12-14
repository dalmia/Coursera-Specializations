#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
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

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,l,r,n;
    map<int, string> m;
    cin>>k;
    vector<string> res;
    map<int, string>::iterator it;
    rep(i, k){
        string q;
        string name;
        cin>>q;
        cin>>n;
        it=m.find(n);
        if(q.compare("add") == 0){
            cin>>name;
            if(it!=m.end())  it->second=name;
            else m.insert(mp(n, name));
        }else if(q.compare("del") == 0) m.erase(n);
        else{
            if(it!=m.end()) res.pb(it->second);
            else res.pb("not found");
        }
    }
    rep(i, res.size()){
        cout<<res[i]<<endl;
    }
}
