#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,j,n) for(int i=j;i<=n;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<int> > graph;
const ll maxw = (ll) 1e4+1;
const ll maxn = (ll) 301;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int la=a.size(), lb=b.size(), lc=c.size();
  int dp[110][110][110];
  rep(i, 110){
      rep(j, 110){
          dp[0][i][j]=0;
          dp[i][0][j]=0;
          dp[i][j][0]=0;
      }
  }

  repr(i, 1, la){
      repr(j, 1, lb){
          repr(k, 1, lc){
              if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
                  dp[i][j][k] = 1+dp[i-1][j-1][k-1];
              }else{
                  dp[i][j][k] = MAX(dp[i-1][j][k], MAX(dp[i][j-1][k], dp[i][j][k-1]));
              }
          }
      }
  }

  return dp[la][lb][lc];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << endl;
}
