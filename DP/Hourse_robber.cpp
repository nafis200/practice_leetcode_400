
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>memo;
int n;

int dp(vector<int>&nums, int i, int p){
    if(i == n){
        return 0;
    }
    if(memo[i][p] != -1){
        return memo[i][p];
    }
   int ans = dp(nums, i + 1, 0);
   if(p != 1){
     ans = max(ans, dp(nums, i + 1, 1) + nums[i]);
   }
   return memo[i][p] = ans;
}

int rob(vector<int>& nums) {
   n = nums.size();
   memo.assign(n, vector<int>(2, -1));
   int ans = 0;
   ans = dp(nums, 1, 1) + nums[0];
   ans = max(ans, dp(nums, 1, 0));
   return ans;
   
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2,7,9,3,1};
    cout << rob(nums) << "\n";
}