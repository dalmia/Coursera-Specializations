#include <iostream>
#include <vector>

using std::vector;
using namespace std;
#define MAX(x,y) ((x)>(y)?(x):(y))

int optimal_weight(int W, const vector<int> &w,int index) {
  //write your code here
  if(W==0 || index==w.size()) return 0;
  if(w[index]>W) return optimal_weight(W,w,index+1);
  int weights=MAX(w[index]+optimal_weight(W-w[index],w,index+1),optimal_weight(W,w,index+1));

  return weights;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w,0) << '\n';
}
