#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <limits.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define pb push_back
#define mp make_pair
//#define DBL_MAX (double)1e10
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,j,n) for(int i=j;i<=n;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<int> > graph;
const ll maxn = (ll) 1e5+9;
const ll mod = (ll) 1e9+7;

//ll a[maxn];
//ll dp[1024][1024];

bool sortx(pair<int, int> l, pair<int, int> r){
    if(l.first != r.first) return l.first < r.first;
    else return l.second<r.second;
}

bool sorty(pair<int, int> l, pair<int, int> r){
    if(r.second != l.second) return l.second < r.second;
    else return l.first < r.first;
}

double brute(pair<int, int> pts[], int n){
    double min = LLONG_MAX;
    rep(i, n-1){
        repr(j, i+1, n-1){
            double dist = sqrt(pow(pts[i].first-pts[j].first, 2) + pow(pts[i].second-pts[j].second, 2));
            min = MIN(dist, min);
        }
    }
    return min;
}

double strip_min(vector<pair<int, int> > s, double d){
    double min=d;
    int n=s.size();
    sort(s.begin(), s.end(), sorty);
    rep(i, n){
        for(int j=i+1; j<n && (s[j].second-s[i].second)<d; j++){
            double dist = sqrt(pow(s[i].first-s[j].first, 2) + pow(s[i].second-s[j].second, 2));
            if(dist<min){
                min = dist;
            }
        }
    }
    return min;
}

double min_dist(pair<int, int> pts[], int n){
    if(n<=3) return brute(pts, n);
    int mid = n/2;
    double d1 = min_dist(pts, mid);
    double d2 = min_dist(pts+mid, n-mid);
    double d = MIN(d1, d2);
    vector<pair<int, int> > s;
    rep(i, n){
        if(abs(pts[i].first - pts[mid].first)<=d){
            s.pb(pts[i]);
        }
    }
    return strip_min(s, d);
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,r,n;
    cin>>n;
    pair<int, int> pts[n];
    rep(i, n){
        cin>>j>>k;
        pts[i] = mp(j, k);
    }
    sort(pts, pts+n, sortx);
    cout<<setprecision(9)<<min_dist(pts, n)<<endl;

}
