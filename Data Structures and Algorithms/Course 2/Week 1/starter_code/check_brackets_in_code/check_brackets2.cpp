#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

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
	ll i,j,k,t,q,m,l,r,n;
    stack<pair<char, int> > st;
    string s;
    cin>>s;
    rep(i, s.length()){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            st.push(mp(s[i],i));
        }else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(st.empty() || s[i]=='}' && st.top().first!='{' || s[i]==')' && st.top().first!='(' || s[i]==']' && st.top().first!='['){
                cout<<i+1<<endl;
                break;
            }else{
                st.pop();
            }
        }
    }
    if(i==s.length()){
        if(st.empty()) cout<<"Success"<<endl;
        else cout<<st.top().second+1<<endl;
    }
}
