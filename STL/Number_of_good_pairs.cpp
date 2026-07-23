
#include<bits/stdc++.h>
using namespace std;
int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int,int>mp;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
         if(mp.find(nums[i]) != mp.end()){
            count += mp[nums[i]];
         }
         mp[nums[i]]++;
    }
    return count;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}