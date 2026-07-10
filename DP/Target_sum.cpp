
#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int, int>, int> memo;

int sum;
int dp(int i, vector<int>& nums, int target) {
  if (i == n) {
    if (target == sum) {
      return 1;
    }
    return 0;
  }
  if (memo.find({i, target}) != memo.end()) {
    return memo[{i, target}];
  }
  int ans = 0;
  ans = dp(i + 1, nums, target + nums[i]) + dp(i + 1, nums, target - nums[i]);
  return memo[{i, target}] = ans;
}
int findTargetSumWays(vector<int>& nums, int target) {
  n = nums.size();

  sum = target;
  return dp(0, nums, 0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int target = 3;
  vector<int> nums = {1, 1, 1, 1, 1};
  cout << findTargetSumWays(nums, target) << "\n";
}