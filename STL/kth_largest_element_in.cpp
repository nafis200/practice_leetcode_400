
#include <bits/stdc++.h>
using namespace std;
class KthLargest {
  priority_queue<int, vector<int>, greater<int>> pq;
  int kthValue;
git a
 public:
  KthLargest(int k, vector<int>& nums) {
    kthValue = k;
    for (int i = 0; i < nums.size(); i++) {
      pq.push(nums[i]);
      if (pq.size() > kthValue) {
        pq.pop();
      }
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > kthValue) {
      pq.pop();
    }
    return pq.top();
  }
};

// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

//  10 9 8 5 5 4 4 3 2

//  4 5 5 8 8

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}