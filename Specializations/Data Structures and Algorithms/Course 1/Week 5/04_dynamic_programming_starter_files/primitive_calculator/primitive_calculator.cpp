#include <iostream>
#include <vector>
#include<string.h>
#include <algorithm>

using namespace std;
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  int count[n+1];
  int p[n+1];
  p[1]=0;
  memset(count,-1,sizeof(count));
  count[1]=0;
  for (size_t i = 1; i <=n; i++) {
	if(count[i]>=0){
		if(i*2<=n){
		  	if(count[i*2]==-1||count[i*2]>count[i]+1){
				count[i*2]=count[i]+1;
				p[i*2]=i;
			}
		}
		if(i*3<=n){
		  	if(count[i*3]==-1||count[i*3]>count[i]+1){
				count[i*3]=count[i]+1;
				p[i*3]=i;
			}
		}
		if(i+1<=n){
		  	if(count[i+1]==-1||count[i+1]>count[i]+1){
				count[i+1]=count[i]+1;
				p[i+1]=i;
			}
		}
	}
  }
  int pa=p[n];
  sequence.push_back(n);
  while(pa!=0){
	  sequence.push_back(pa);
	  pa=p[pa];
  }
  reverse(sequence.begin(),sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
