#include <iostream>
#include <string>

using std::string;
using namespace std;

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define repr(i,j,n) for(int i=j;i<n;i++)

int edit_distance(const string &str1, const string &str2) {
  int a=str1.length();
  int b=str2.length();
  int m[a+1][b+1];
  m[0][0]=0;
  repr(i,0,b+1) m[0][i]=i;
  repr(i,0,a+1) m[i][0]=i;
  repr(i,1,a+1){
	  repr(j,1,b+1){
		  if(str1[i-1]==str2[j-1]){
			  m[i][j]=m[i-1][j-1];
		  }
		  else{
			  m[i][j]=1+MIN(m[i-1][j],MIN(m[i][j-1],m[i-1][j-1]));
		  }
	  }
  }
  return m[a][b];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
