#include <iostream>
#define maxn (int)1e6
using namespace std;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;
	long long fib[maxn];
    fib[0] = 0;
    fib[1] = 1;
	fib[2] = 2;
	int count=2;

	if(m==2) count=3;
	else{
	    for (long long i = 2; i <=n ; ++i) {
			//std::cout << count << std::endl;
			//cout<<(fib[i-1] + fib[i-2])%m;
			//std::cout << count << std::endl;
	        fib[i] = (fib[i-1] + fib[i-2])%m;
			//std::cout << count << std::endl;
			if(i>0 && fib[i]==1 && fib[i-1]==0) {
				count--;
				break;
			}
			count++;
	    }
	}
	//std::cout << count << std::endl;
	n=n%count;

    return fib[n] % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
