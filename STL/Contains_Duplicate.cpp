
#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
   sort(nums.begin(), nums.end());

   for(int i = 1; i < nums.size(); i++){
      if(nums[i] == nums[i - 1]){
        return true;
      }
   }
   return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 1};

    cout << containsDuplicate(nums) << "\n";
}