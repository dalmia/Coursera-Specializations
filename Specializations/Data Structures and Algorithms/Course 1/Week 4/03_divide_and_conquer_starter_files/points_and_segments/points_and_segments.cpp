#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

struct sortval{
	bool operator()(pair<int,int> a,pair<int,int> b){
		return a.first<b.first;
	}
};


int calc(std::vector< pair<int,int> > v,int point,int l,int r){
	if(l>r) return 0;
	int mid=(l+r)/2;
	// cout<<"mid"<<mid<<endl;
	// cout<<point<<endl;
	// cout<<v[mid].first<<" "<<v[mid].second<<endl;
	// cout<<endl;
	if(v[mid].first>point) return calc(v,point,l,mid-1);
	if(v[mid].second<point) return calc(v,point,mid+1,r);
	return 1+calc(v,point,l,mid-1)+calc(v,point,mid+1,r);
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  std::vector< pair<int,int> > pairs(starts.size());
  for (int i = 0; i < starts.size(); i++) {
  	pairs[i]=make_pair(starts[i],ends[i]);
	// cout<<"S"<<starts[i];
	// cout<<pairs[i].first<<endl;
  }
  sort(pairs.begin(),pairs.end(),sortval());
  for (int i = 0; i < starts.size(); i++) {
  	cout<<pairs[i].first<<endl;
  }
  for (size_t i = 0; i < points.size(); i++) {
  	cnt[i]=calc(pairs,points[i],0,starts.size()-1);
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
