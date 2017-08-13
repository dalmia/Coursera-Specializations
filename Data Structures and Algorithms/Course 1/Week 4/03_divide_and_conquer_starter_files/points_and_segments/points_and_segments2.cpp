#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define pb push_back
#define mp make_pair

typedef long long ll;
using namespace std;
const int maxn = 1e5+9;

vector<int> starts(maxn), ens(maxn), points(maxn);

bool comp(const pair<int, char> l, const pair<int, char> r){ return l.first < r.first; }

vector<int> fast_count_segments() {
  vector<int> cnt(points.size());
  vector<pair<int, char> > point_values;
  map<int, vector<int> > map;

  for(int i=0; i<starts.size(); i++){
      point_values.pb(mp(starts[i], 's'));
  }
  for(int i=0; i<points.size(); i++){
      int point = points[i];
      map[point].pb(i);
      point_values.pb(mp(point, 'p'));
  }
  for(int i=0; i<ens.size(); i++){
      point_values.pb(mp(ens[i], 'e'));
  }
  sort(point_values.begin(), point_values.end(), comp);
  int val=0;
  for (size_t i = 0; i < point_values.size(); i++) {
      pair<int, char> point = point_values[i];
      if(point.second == 's') val += 1;
      else if(point.second == 'e') val -= 1;
      else{
          std::vector<int> in = map[point.first];
          for(int j=0; j<in.size(); j++){
              cnt[j] = val;
          }
      }
  }

  return cnt;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> starts[i] >> ens[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> points[i];
    cout<<2;
  }
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }

}
