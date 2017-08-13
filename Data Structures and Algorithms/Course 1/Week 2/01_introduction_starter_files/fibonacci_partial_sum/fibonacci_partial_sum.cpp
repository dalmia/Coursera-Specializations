#include <iostream>
#include <vector>
using std::vector;
using namespace std;

#define maxn (int)1e5

long long get_fibonacci_partial_sum_naive(long long m, long long n) {
    if (n <= 1)
        return n;

	int fsum[60];
    fsum[0]=0;
	fsum[1]=1;
    int prev=0, next=1;

	for (int i = 2; i < 60; ++i) {
        int current = prev+next;
        fsum[i] = (fsum[i-1] + current) % 10;
        prev=next;
        next=current;
    }

    m = m%60;
    n = n%60;
    int dig = (fsum[n] - (m>0? fsum[m-1]:0))%10;
    return (dig+10)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
