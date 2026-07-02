

#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
  if (nums.size() < 2) {
    return nums.size();
  }
  int n = nums.size();
  int j = 2;
  for (int i = 2; i < n; i++) {
    if (nums[i] != nums[j - 2]) {
      nums[j] = nums[i];
      j++;
    }
  }
  return j;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

  int ans = removeDuplicates(nums);
  cout << ans << "\n";
}

//  0,0,1,1,1,1,2,3,3
