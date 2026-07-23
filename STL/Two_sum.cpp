
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i = 0; i < nums.size(); i++){
         int x = target - nums[i];

         if(mp.find(x) != mp.end()){
             ans.push_back(mp[x]);
             ans.push_back(i);
             break;
         }

         mp[nums[i]] = i;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}