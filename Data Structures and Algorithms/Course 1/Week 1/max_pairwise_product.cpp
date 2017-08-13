#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i,n) for(int i=0;i<n;i++)
#define repr(a,b,n) for(int a=b;a<n;a++)
#define endl '\n'
#define ll long long

using namespace std;

int main(){
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	rep(i,n) std::cin >> numbers[i];
	std::sort(numbers.begin(),numbers.end());
	ll result=((ll)numbers[n-1])*numbers[n-2];
	cout<<result<<endl;
	return 0;
}
