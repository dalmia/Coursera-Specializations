#include <iostream>
#include <vector>

using std::vector;

long long merge(std::vector<int> &a, vector<int> &b, int left, int mid, int right){
    int i=0, j=left, k=mid+1;
    long long count=0;
    for(; i<right-left+1; i++){
        if(j>mid){
            b[i]=a[k++];
        }else if(k>right){
            b[i]=a[j++];
        }else if(a[j]<=a[k]){
            b[i]=a[j++];
        }else{
            count += mid-j+1;
            b[i]=a[k++];
        }
    }
    for(int i=0; i<right-left+1; i++){
        a[left+i] = b[i];
    }
    return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  int ave = (left + right) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions += merge(a, b, left, ave, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
