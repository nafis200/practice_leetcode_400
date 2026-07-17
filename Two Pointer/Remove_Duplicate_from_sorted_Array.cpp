
#include <bits/stdc++.h>
using namespace std;

//  1 1 2 2 3

//  1 2 2 2 3

// 1 2 3 4 5 6

// i = 0 j = 1

int removeDuplicates(vector<int>& nums) {
   int n = nums.size();
   int i = 0;
   int j = i + 1;
   while(j < n){
      while(j < n && nums[i] == nums[j]){
        j++;
      }
      if(j >= n){
         break;
      }
      nums[i + 1] = nums[j];
      i++;
      j++;
   }
   return i + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4};
  

}

// 0 1 0 3 12

//  1 3 0 0 12
