
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
   int l = 0, r = numbers.size() - 1;
   vector<int>ans;
   while(l < r){
      if(numbers[l] + numbers[r] == target){
          ans.push_back(l + 1);
          ans.push_back(r + 1);
          break;
      }
      if(numbers[l] + numbers[r] < target){
         l++;
      }
      else{
         r--;
      }
   }  
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>numbers = {2,7,11,15};
    int target = 9;
    vector<int>ans = twoSum(numbers, target);
}