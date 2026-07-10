#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<vector<int>>> memo;
vector<int>num;
int dp(int i, int take, int first){
    if(i == n){
        return 0;
    }
    if(memo[i][take][first] != -1){
       return memo[i][take][first];   
    }
    int ans = dp(i + 1, 0, first);
    if(i == n - 1){
         if(take == 0 && first == 0){
            ans =max(ans,dp(i + 1, 1, first) + num[i]); 
         }
    }
    else{
        if(take == 0){
            ans =max(ans,dp(i + 1, 1, first) + num[i]); 
        }
    }
    return memo[i][take][first] = ans;
}

int rob(vector<int>& nums) {
   n = nums.size();
   memo.assign(n, vector<vector<int>>(2, vector<int>(2, -1)));
   n = nums.size(); 
   num = nums;
   int ans = dp(1, 1, 1) + nums[0];
   ans = max(ans, dp(1, 0, 0));
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 1};
    cout << rob(nums) << "\n";
}