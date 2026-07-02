#include <bits/stdc++.h>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
  int n = nums.size();
  vector<string> ans;
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    l = i;
    r = i + 1;
    while (r < n && nums[r] - 1 == nums[r - 1]) {
      r++;
    }

    string s;
    string lower = to_string(nums[l]);
    string upper = to_string(nums[r - 1]);
    if (lower == upper) {
      s = lower;
    } else {
      s = to_string(nums[l]);
      s += "->";
      s += to_string(nums[r - 1]);
    }
    i = r - 1;
    ans.push_back(s);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
  vector<string> ans = summaryRanges(nums);
  for (auto v : ans) {
    cout << v << "\n";
  }
}

//  0 1 2 4 5 7
//  r = 3
//  0--> 2
//  4--> 5
//  7--> 7