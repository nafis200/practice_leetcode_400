#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>>vis,memo;
int n;
bool dp(int i, int target, vector<int>& nums){
    if(i == n){
        if(target == 0){
            return true;
        }
        return false;
    }
    if(target < 0){
        return false;
    }
    if(vis[i][target] == true){
        return memo[i][target];
    }
    bool ans = false;
    ans = dp(i + 1, target, nums);
    ans |= dp(i + 1, target - nums[i], nums);
    vis[i][target] = true;
    return memo[i][target] = ans;
}

 bool canPartition(vector<int>& nums) {
   int sum = 0;
   for(auto num : nums){
      sum += num;
   }
   if(sum % 2){
     return false;
   }
   n = nums.size();
   vis.assign(n, vector<bool>(sum, false));
   memo.assign(n, vector<bool>(sum, false));
   return dp(0, sum / 2, nums);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,5,11,5};
    cout << canPartition(nums) << "\n";
}