
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>memo;
int dp(int target,vector<int>& nums){
    if(target == 0){
        return 1;
    }
    if(target < 0){
        return 0;
    }
    if(memo[target] != -1){
        return memo[target];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += dp(target - nums[i], nums);
    }
    return memo[target] = ans;
}
int combinationSum4(vector<int>& nums, int target) {
    n = nums.size();
    memo.assign(target + 1,-1);
    return dp(target, nums);
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    vector<int>nums = {1,2,3};
    int  target = 4;
    cout << combinationSum4(nums, target) << "\n";
}