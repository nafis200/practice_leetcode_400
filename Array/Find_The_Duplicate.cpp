
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
   int slow = nums[0];
   int fast = nums[nums[0]];

   while(fast != slow){
        slow = nums[slow];
        fast = nums[nums[fast]];
   }

   fast = 0;
   while(fast != slow){
      fast = nums[fast];
      slow = nums[slow];
   }
   return fast;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


// 5 
// 1,3,4,2,2

//  x    y     z



//  0 --> 1
//  1 --> 3
//  2 --> 4
//  3 --> 2
//  4 --> 2

