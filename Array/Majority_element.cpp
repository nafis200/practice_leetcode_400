
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
    int ans = nums[0];
    int power = 0;
    for(int i = 0; i < nums.size(); i++){
        if(power == 0){
            ans = nums[i];
         }
         if(nums[i] == ans){
            power++;
         }
         else{
            power--;
         }    
    }
    return ans;
}
//  3 3 4
//  3 4 3
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

