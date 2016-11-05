#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left > right) return -1;
  if (left == right) return a[left];
  sort(a.begin(),a.end());
  int count=1;
  for (size_t i = 0; i < a.size()-1; i++) {
  	if(a[i]==a[i+1]){
		count++;
		if(count>a.size()/2) return 1;
	}else count=1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
