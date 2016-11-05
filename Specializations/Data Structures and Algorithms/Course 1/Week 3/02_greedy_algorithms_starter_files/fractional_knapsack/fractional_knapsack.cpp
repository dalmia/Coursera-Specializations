#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;
using namespace std;

struct sortval{
	bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right){
		return ((float)left.first)/left.second>((float)right.first)/right.second;
	}
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  std::vector< pair<int,int> > p;
  int n=weights.size();
  for (int i = 0; i < n; i++) {
	p.push_back(make_pair(values[i],weights[i]));
  }

  sort(p.begin(),p.end(),sortval());
  int i=0;

  while(i<n && capacity>0){
	if(capacity>=p[i].second){
		capacity-=p[i].second;
		value+=p[i].first;
	}else{
		value+=((float)capacity/p[i].second)*p[i].first;
		capacity=0;

	}
	i++;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
