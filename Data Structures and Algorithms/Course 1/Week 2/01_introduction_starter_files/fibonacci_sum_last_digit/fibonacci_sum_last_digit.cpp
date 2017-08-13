#include <iostream>
using namespace std;
#define maxn (int)1e5

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

	long long fsum[maxn];
    long long previous = 0;
    long long current  = 1;
    fsum[0]=0;
	fsum[1]=1;
	int count=2;

	for (long long i = 2; i <= n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        fsum[i]=(fsum[i-1]+current)%10;
		if(fsum[i]==1 && fsum[i-1]==0){
			count--;
			break;
		}
		count++;
    }

	n=n%count;
    return fsum[n] % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
