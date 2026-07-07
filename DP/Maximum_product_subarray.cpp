
#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
     
    int mn = nums[0];
    int mx = nums[0];
    int ans = INT_MIN;
    for(int i = 1; i < nums.size(); i++){
        
        if(nums[i] < 0){
            swap(mn, mx);
        }

        mx = max(nums[i], mx * nums[i]);
        mn = min(nums[i],mn * nums[i]);

        ans = max(ans, mx);
    }
    return ans;
       
}
int32_t main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int>nums = {2,3,-2,4};

   int ans = maxProduct(nums);
   cout << ans << "\n";
}