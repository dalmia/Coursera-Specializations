#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#ifndef ONLINE_JUDGE
	#define ONLINE_JUDGE
#endif

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
const ll maxn = (ll) 2e5+9;
const ll mod = (ll) 1e9+7;
int a[maxn],b[maxn];
vector<vector<int> > adjlist(maxn);
vector<bool> vis(maxn);
vector<bool> vis2(maxn);
int cnt,best;
void dfs(int);
void dfs2(int);

int main()
{
	//std::ios::sync_with_stdio(0);
	int i,j,k,t,q,m,l,r,n;
	scanf("%d%d%d",&n,&m,&k);
	repr(i,1,n)scanf("%d",a+i);
	rep(i,m) {
		scanf("%d%d",&j,&k);
		adjlist[j].pb(k);
		adjlist[k].pb(j);
	}
	int ans=0;
	repr(i,1,n) {
		if(!vis[i]) {
			cnt=0;best=0;
			dfs(i);
			dfs2(i);
			if(cnt>1)ans+=cnt-best;
		}
	}
	printf("%d\n",ans);
}

void dfs(int node) {
	b[a[node]]++;
	best=MAX(best,b[a[node]]);
	cnt++;
	vis[node]=true;
	for(int i=0;i<adjlist[node].size();i++) {
		int j=adjlist[node][i];
		if(!vis[j]) {
			dfs(j);
		}
	}
}

void dfs2(int node) {
	b[a[node]]=0;
	vis2[node]=true;
	for(int i=0;i<adjlist[node].size();i++) {
		int j=adjlist[node][i];
		if(!vis2[j]) {
			dfs2(j);
		}
	}
}
