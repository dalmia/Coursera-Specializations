#include <iostream>
#include <vector>

using std::vector;
using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int i=1,sum=0;
  while(sum<n){
	  if(2*i+1>n-sum){
		  summands.push_back(n-sum);
		  sum=n;
	  }else{
		  summands.push_back(i);
		  sum+=i;
		  i++;
	  }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
