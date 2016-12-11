#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::numeric_limits;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long* MinAndMax(int i, int j, const vector<char> &op, vector<vector<long long> > &m, vector<vector<long long> > &M) {
	long long mmin = numeric_limits<long long>::infinity();
	long long mmax = - numeric_limits<long long>::infinity();
	// long long mmin = 10000;
	// long long mmax = -10000;
	for(int k=i;k<j;k++) {
		long long a = eval(M[i][k], M[k+1][j], op[k]);
		long long b = eval(M[i][k], m[k+1][j], op[k]);
		long long c = eval(m[i][k], M[k+1][j], op[k]);
		long long d = eval(m[i][k], m[k+1][j], op[k]);
		mmin = min(min(min(min(mmin, a), b), c), d);
        mmax = max(max(max(max(mmax, a), b), c), d);
	}
	static long long result[2];
	result[0] = mmin;
	result[1] = mmax;
	return result;
}

long long get_maximum_value(const string &exp) {
	long long max = 0;
	vector<char> op;
	vector<int> digit;
  	for(int i=0;i<exp.length();i++) {
		if(i%2 == 0) { // digit
			digit.push_back(exp.at(i)-'0');
		}
		else { // operand
			op.push_back(exp.at(i));
		}
	}
	int n = digit.size();
	vector<vector<long long> > m(n, vector<long long>(n, 0));
	vector<vector<long long> > M(n, vector<long long>(n, 0));
	for(int i = 0;i<n;i++) {
		m[i][i] = digit.at(i);
		M[i][i] = digit.at(i);
	}
	for(int s=1;s<n;s++) {
		for(int i=0;i<n-s;i++) {
			int j = i+s;
			long long *temp;
			temp = MinAndMax(i,j,op,m,M);
			m[i][j] = temp[0];
			M[i][j] = temp[1];
		}
	}
	return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
