#include <bits/stdc++.h>
using namespace std;
// bool canJump(vector<int>& nums){
//     int jump = 0;
//     int next_target = 0;
//     int mx = 0;
//     for(int i = 0; i < nums.size(); i++){
//         if(i > next_target){
//             jump = -1;
//             break;
//         }
//         mx = max(mx, nums[i] + i);
//         if(next_target >= nums.size() - 1){
//             jump = 1;
//             break;
//         }
//         if(i == next_target){
//             next_target = mx;
//             jump++;
//         }
//     }
//     if(jump == -1){
//         return false;
//     }
//     return true;
// }


// Time o(n^2)

//  (n - i - 1)

//  n - (i) - 1
//  i * (i + 1) / 2
//  i^2

int jump(vector<int>& nums) {
  vector<int> dp(nums.size(), INT_MAX - 2);
  dp[0] = 0;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
      if (j + i < nums.size()) {
        dp[j + i] = min(dp[j + i], dp[i] + 1);
      }
    }
  }

  if (dp[nums.size() - 1] == INT_MAX - 2) {
    return -1;
  }
  return dp[nums.size() - 1];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {3, 2, 1, 0, 4};
  cout << jump(nums) << "\n";
}

//  2 3 1 1 4

//  jump = 0
//     cur = 2

// 3 2 0 4 1
//  3 3
//      3