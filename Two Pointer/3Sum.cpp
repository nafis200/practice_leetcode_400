
#include <bits/stdc++.h>
using namespace std;
// vector<vector<int>> threeSum(vector<int>& nums) {
//   sort(nums.begin(), nums.end());
//   set<vector<int>> st;
//   int n = nums.size();
//   for (int i = 0; i < n - 2; i++) {
//     int l = i + 1;
//     int r = n - 1;
//     while (l < r) {
//       int sum = nums[i] + nums[l] + nums[r];
//       if (sum == 0) {
//         vector<int> v;
//         v.push_back(nums[i]);
//         v.push_back(nums[l]);
//         v.push_back(nums[r]);
//         st.insert(v);
//         l++;
//         r--;
//       } else if (sum > 0) {
//         r--;
//       } else {
//         l++;
//       }
//     }
//   }
//   vector<vector<int>> ans;
//   for (auto v : st) {
//     ans.push_back(v);
//   }
//   return ans;
// }

//  0 0 0 0 0 0 0 0 0 0 0 

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>>ans;
  int n = nums.size();
  for (int i = 0; i < n - 2; i++) {
    if(i > 0 && nums[i] == nums[i - 1]){
        continue;
    }
    int l = i + 1;
    int r = n - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      if(l - 1 > i && nums[l] == nums[l - 1]){
          l++;
          continue;
      }
      if(r + 1 < n && nums[r] == nums[r + 1]){
        r--;
        continue;
      }
      if (sum == 0) {
        vector<int> v;
        v.push_back(nums[i]);
        v.push_back(nums[l]);
        v.push_back(nums[r]);
        ans.push_back(v);
        
        l++;
        r--;
      } else if (sum > 0) {
        r--;
      } else {
        l++;
      }
    }
  }
  return ans;
}

//  -4 -1 -1 0 1 2

//  -1

// sum = -1;

//  l = -1     r = 2

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = threeSum(nums);

  for (auto v : ans) {
    cout << "[";
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "]\n";
  }
}
