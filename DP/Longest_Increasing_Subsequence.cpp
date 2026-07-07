#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    set<int>st;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
      auto it = st.lower_bound(nums[i]);

      if(it != st.end()){
         st.erase(it);
      }
      st.insert(nums[i]);
      ans = max(ans,(int)st.size());
    }
   return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  int ans = lengthOfLIS(nums);
  cout << ans << "\n";
}

// 0 1 0 3 2 3
//  0 1 3 