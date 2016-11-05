#include <iostream>
#include <vector>
using std::vector;
using namespace std;

#define maxn (int)1e5

long long get_fibonacci_partial_sum_naive(long long m, long long n) {
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

	cout<<count<<endl;
	int t_n=n%count;
	int t_m=m%count;
	int sum=0;

	if(t_m<t_n){
		sum=fsum[t_n]-fsum[t_m];
	}else{
		sum+=fsum[t_n];
		if(t_m>0){
			sum+=fsum[count]-fsum[t_m];
		}else sum+=fsum[count];
	}
    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
