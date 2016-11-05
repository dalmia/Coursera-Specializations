#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

struct Segment {
  int start, end;

  bool operator<(const Segment& seg) const
  {
	  return end<seg.end;
  }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  int n=segments.size();
  sort(segments.begin(),segments.end());

  int count=1;
  int point=segments[0].end;
  points.push_back(point);
  while(count<n){
	  if(segments[count].start>point){
		  point=segments[count].end;
		  points.push_back(point);
	  }
	  count++;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
