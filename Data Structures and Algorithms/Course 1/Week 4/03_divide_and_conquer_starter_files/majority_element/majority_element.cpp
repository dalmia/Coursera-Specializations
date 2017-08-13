#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for(i=0, i<n; i++)
#define repr(i, j, n) for(int i=j; i<=n; i++)

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  sort(a.begin(), a.end());
  int count=1;
  repr(i, 1, right-1){
      if(a[i] == a[i-1]){
          count++;
          if(count>right/2) return a[i];
      }else{
          count=1;
      }
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
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
