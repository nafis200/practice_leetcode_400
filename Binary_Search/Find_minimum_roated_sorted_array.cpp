
#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(nums[l] == nums[mid] && nums[r] == nums[mid]){
             l++;
             r--;
             continue;
        }
        if(nums[mid] > nums[r]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }    
    return nums[l];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 3, 3};
    cout << findMin(nums) << "\n";
}