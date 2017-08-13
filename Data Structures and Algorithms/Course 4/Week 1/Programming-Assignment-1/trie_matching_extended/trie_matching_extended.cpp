#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

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
map<ll, set<char> > m;
map<pair<ll, char>,ll> s;
ll n=0;

//ll a[maxn];
//ll dp[1024][1024];
void add(string p){
    ll i,c=0;
    rep(i, p.length()){
        set<char> sc=m[c];
        if(sc.find(p[i]) != sc.end()){
            c=s[mp(c,p[i])];
        }else{
            n++;
            s.insert(mp( mp(c,p[i]) ,n));
            sc.insert(p[i]);
            m[c]=sc;
            c=n;
        }
        if(i==p.length()-1) m[c].insert('$');
    }
}

bool match(string t,ll k){
    ll c=0;

    while(true){
        set<char> sc=m[c];
        if(sc.find('$')!=sc.end()) return true;
        else if(sc.find(t[k])!=sc.end()){
            //cout<<k<<" ";
            c = s[mp(c,t[k])];
            //cout<<c<<" "<<m[c].size()<<endl;
            k++;
        }else return false;
    }
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,l,r,n;
    string text;
    cin>>text;
    text += '$';
    cin>>n;
    // set<char> e;
    // e.insert('$');
    // m.insert(mp(0, e));
    rep(i, n){
        string p;
        cin>>p;
        add(p+'$');
    }
    // map<pair<ll, char>, ll>::iterator it;
    // for(it = s.begin(); it!=s.end(); it++){
    //     cout<<it->first.first<<"->"<<it->second<<":"<<it->first.second<<endl;
    // }
    vector<ll> res;
    rep(i,text.length()){
        if(match(text,i)){
            //cout<<i<<endl;
            res.pb(i);
        }
    }
    rep(i, res.size()) cout<<res[i]<<" ";
    cout<<endl;
}
