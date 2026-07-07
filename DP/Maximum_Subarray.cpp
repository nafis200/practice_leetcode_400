
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {
   int mx = INT_MIN;
   int sum = 0;
   for(int i = 0; i < nums.size(); i++){
       sum += nums[i];
       mx = max(mx, sum);
       if(sum < 0){
          sum = 0;
       }
   }
   return mx;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(nums) << "\n";
}