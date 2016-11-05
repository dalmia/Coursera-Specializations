#include <iostream>

int gcd(int a, int b) {
  while(b>0){
	int temp=a;
	a=b;
	b=temp%b;
  }
  return a;
}

long long lcm_naive(int a, int b) {
  return (((long long)a)*b)/gcd(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
