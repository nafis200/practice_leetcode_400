
#include<bits/stdc++.h>
using namespace std;
// int firstMissingPositive(vector<int>& nums) {
//   unordered_set<int>st;
//   for(auto i : nums){
//      if(i > 0){
//         st.insert(i);
//      }
//   }
//   int ans = 0;
//   for(int i = 1; i <= 1e9; i++){
//      if(st.find(i) == st.end()){
//         ans = i;
//         break;
//      }
//   }
//   return ans;
// }

int firstMissingPositive(vector<int>& nums) {
  int n = nums.size();
  int ans = n + 1;
  for(int i = 0; i < n; i++){

     while(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1]){
        swap(nums[i], nums[nums[i] - 1]);
     }
  }

  for(int i = 0; i < n; i++){
     if(nums[i] != i + 1){
        ans = i + 1;
        break;
     }
  }
  return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={3,4,-1,1};
    //  3 == 2
    //  nums[i] = 3  nums[nums[i] - 1]

    int ans = firstMissingPositive(nums);
    for(auto v : nums){
        cout << v << " ";
    }
    cout << "\n";
    cout << ans << "\n";

}