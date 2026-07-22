#include<bits/stdc++.h>
using namespace std;
 vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = -1, ans1 = -1;
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target){
             ans = mid;
             r = mid - 1;
        }
        else if(nums[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target){
             ans1 = mid;
             l = mid + 1;
        }
        else if(nums[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    vector<int>v;
    v.push_back(ans);
    v.push_back(ans1);
    return v;

 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={5,7,7,8,8,10};
    int target = 8;
    vector<int>ans = searchRange(nums,target);

    for(auto i : ans){
        cout << i << " ";
    }
}