
#include <bits/stdc++.h>
using namespace std;
 vector<int> sortArrayByParity(vector<int>& nums) {
     int i = 0;
     int n = (int)nums.size();
     for(i; i < n; i++){
        if(nums[i] % 2 == 1){
            break;
        }
     }
     for(int j = i + 1; j < n; j++){
        if(nums[j] % 2 == 0){
            swap(nums[i],nums[j]);
            i++;
        }
     }
     return nums;
 }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>nums = {0,1,2};
  nums = sortArrayByParity(nums);
  for(auto i : nums){
    cout << i << " ";
  }

}

