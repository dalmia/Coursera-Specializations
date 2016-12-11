#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

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
ll dp[20][20];
ll minv[20][20];
ll maxv[20][20];

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  }
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n;

    string s;
    std::cin >> s;
    int d = (s.length()+1)/2;

    repr(i, 1, d){
        dp[i][i] = s[2*(i-1)]-'0';
        maxv[i][i] = s[2*(i-1)]-'0';
        minv[i][i] = s[2*(i-1)]-'0';
    }
    // repr(i, 1, d){
    //     repr(j, 1, d){
    //         maxv[i][j]=-1e10;
    //         minv[i][j]=1e10;
    //     }
    // }
    // repr(i, 1, d){
    //     repr(j, 1, d){
    //         cout<<minv[i][j];
    //     }
    //     cout<<endl;
    // }

    repr(k, 2, d){
        repr(i, 1, d-k+1){
            j=i+k-1;
            if(k==2){
                minv[i][j]=maxv[i][j]=eval(dp[i][i], dp[j][j],  s[2*(i-1)+1]);
            }
            else{
                long long mi = numeric_limits<long long>::infinity();
	            long long ma = - numeric_limits<long long>::infinity();

                for(l=2*i; l<2*j; l+=2){
                    ll a,b,c,d;
                    a = eval(maxv[i][l/2], minv[l/2+1][j], s[l-1]);
                    b = eval(minv[i][l/2], maxv[l/2+1][j], s[l-1]);
                    c = eval(maxv[i][l/2], maxv[l/2+1][j], s[l-1]);
                    d = eval(minv[i][l/2], maxv[l/2+1][j], s[l-1]);
                    ma = MAX(ma,MAX(MAX(a,b),MAX(c,d)));
                    mi = MIN(mi,MIN(MIN(a,b),MIN(c,d)));
                    //cout<<ma<<" "<<mi<<endl;
                }

                maxv[i][j]=ma;
                minv[i][j]=mi;
            }

        }
        // repr(i, 1, d){
        //     repr(j, 1, d){
        //         cout<<maxv[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
        // repr(i, 1, d){
        //     repr(j, 1, d){
        //         cout<<minv[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
    }


    cout<<maxv[1][d]<<endl;

}
