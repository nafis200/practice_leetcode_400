
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
 public:
  priority_queue<int, vector<int>, greater<int>> mn;
  priority_queue<int> mx;
  MedianFinder() {}

  void addNum(int num) {
      mx.push(num);
      mn.push(mx.top());
      mx.pop();
      if(mn.size() > mx.size()){
         mx.push(mn.top());
         mn.pop();
      }
  }

  double findMedian() {
     if(mn.size() == mx.size()){
        int x = mn.top();
        int y = mx.top();

        return (x + y) / 2.0;
     }
     else{
        return mx.top() / 1.0;
     }
  }
};

//  2 5 1 4

// 1 2  4 5

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}



