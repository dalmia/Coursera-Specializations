#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

std::vector<int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  int k=j;

  for(int i=j+1; i<=r;i++){
	  if (a[i] == a[j]) {
        k++;
        swap(a[i], a[k]);
      }
  }
  vector<int> list(2);
  list[0]=j;
  list[1]=k;
  return list;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  std::vector<int> v = partition3(a, l, r);

  randomized_quick_sort(a, l, v[0]- 1);
  randomized_quick_sort(a, v[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
