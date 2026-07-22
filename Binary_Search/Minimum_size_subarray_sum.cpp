
#include <bits/stdc++.h>
using namespace std;



// 0 2 5 6 8 12 15

// pref[r] - pref[l] >= target;

//  pref[r] >= pref[l] + target;

int minSubArrayLen(int target, vector<int>& nums) {
  int n = nums.size();
  vector<int>pref(n + 1, 0);
  for(int i = 0; i < n; i++){
      pref[i + 1] = pref[i] + nums[i];
  }

  int ans = INT_MAX;
  for(int i = 0; i <= n; i++){
     int next_target = target + pref[i];

     auto it = lower_bound(pref.begin() + i,pref.end(), next_target);

     if(it != pref.end()){
        int r = it - pref.begin();
        ans = min(ans, r - i);
     }
  }
  if(ans == INT_MAX){
    ans = 0;
  }
  return ans;

}


// int minSubArrayLen(int target, vector<int>& nums) {
//   int n = nums.size();
//   int l = 0, r = 0;
//   int sum = 0;
//   int ans = INT_MAX;
//   while (r < n) {
//     sum += nums[r];

//     while (l <= r && sum >= target) {
//       ans = min(ans, r - l + 1);
//       sum -= nums[l];
//       l++;
//     }
//     r++;
//   }
//   if(ans == INT_MAX){
//     ans = 0;
//   }
//   return ans;
// }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;

  int ans = minSubArrayLen(target, nums);

  cout << ans << "\n";
}