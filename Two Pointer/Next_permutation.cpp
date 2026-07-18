
#include <bits/stdc++.h>
using namespace std;


//  2 3 7 6 5 1

//  pivot = 3
// 3 next bigger close eleemnt = 5

// swap 2 5 7 6 3 1
//     2 5 1 3 6 7

void nextPermutation(vector<int>& nums) {
   int n = nums.size() - 1;
   int j = -1;
   for(int i = n - 1; i >= 0; i--){
      if(nums[i] < nums[i + 1]){
         j = i;
         break;
      }
   }
 
   if(j >= 0){
      int k = n;
      while(nums[k] <= nums[j]){
          k--;
      }
      swap(nums[j], nums[k]);
   }
   reverse(nums.begin() + j + 1, nums.end());
   
}

//  2 3 1
// 

//  2 3 1

//  1 2 3
//  1 3 2
//  2 1 3
//  2 3 1
//  3 1 2
//  3 2 1



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1,3,2};
  
  nextPermutation(nums);
  for(auto i : nums){
    cout << i << " ";
  }
 
}


