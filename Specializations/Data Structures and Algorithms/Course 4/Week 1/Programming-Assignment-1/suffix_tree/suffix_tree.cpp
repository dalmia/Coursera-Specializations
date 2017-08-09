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
map<pair<ll, char>,pair<ll,string> > s;
ll n=0;

//ll a[maxn];
//ll dp[1024][1024];
void add(string p, int k){
    ll i,c=0,j=-1,pr;
    string str;
    repr(i, k, p.length()-1){
        if(j==-1 || j==str.length()){
            j=0;
            set<char> sc=m[c];
            if(sc.find(p[i]) != sc.end()){

                //cout<<"1. "<<k<<" "<<c<<" "<<p[i]<<endl;
                pair<ll, string> pp=s[mp(c,p[i])];
                str=pp.second;
                pr=c;
                c=pp.first;
                j++;
            }else{
                //cout<<"2. "<<k<<" "<<c<<" "<<p[i]<<endl;
                n++;
                s.insert(mp( mp(c,p[i]),mp(n, p.substr(i))));
                sc.insert(p[i]);
                m[c]=sc;
                return;
            }
        }else{
            if(str[j]==p[i]){
                //cout<<"3. "<<k<<" "<<c<<" "<<p[i]<<endl;
                j++;
                continue;
            }
            //cout<<"4. "<<k<<" "<<c<<" "<<p[i]<<endl;

            n++;
            s[mp(pr,str[0])]=mp(n, str.substr(0, j));
            s.insert(mp( mp(n,str[j]),mp(c, str.substr(j))));
            m[n].insert(str[j]);
            n++;
            s.insert(mp( mp(n-1,p[i]),mp(n, p.substr(i))));
            m[n-1].insert(p[i]);
            return;
        }
    }
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,l,r;
    string str;
    cin>>str;
    rep(i,str.length()){
        add(str,i);
    }
    map<pair<ll, char>, pair<ll, string> >::iterator it;
    for(it = s.begin(); it!=s.end(); it++){
        cout<<it->second.second<<endl;
    }
    //cout<<n<<endl;
}
