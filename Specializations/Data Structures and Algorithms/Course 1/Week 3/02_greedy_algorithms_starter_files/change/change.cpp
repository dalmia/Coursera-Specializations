#include <iostream>

int get_change(int m) {
  //write your code here
  int n=0;
  if(m>=10){
	n+=m/10;
	m=m%10;

  }
  if(m>=5){
	n+=m/5;
	m=m%5;

  }
  if(m>=1){
	n+=m;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
