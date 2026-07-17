
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
  int n = nums.size();
  int i = 0;
  for (i; i < n; i++) {
    if (nums[i] == 0) {
      break;
    }
  }
  for (int j = i + 1; j < n; j++) {
    if (nums[j] != 0) {
      swap(nums[i], nums[j]);
      i++;
    }
  }

}
//  0 1 0 3 12

//  1 3 12 0 0


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0, 1, 0, 3, 12};
  moveZeroes(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
}

// 0 1 0 3 12

//  1 3 0 0 12
