
#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    bool ans = false;
    int mid = 0;
    while(l <= r){
        mid = (l + r) / 2;
        if(nums[mid] == target){
             ans = true;
             break;
        }
        
        if(nums[l] == nums[mid] && nums[mid] == nums[r]){
               l++;
               r--;
        }

        if(nums[mid] >= nums[l]){
           if(nums[l] <= target && nums[mid] > target){
              r = mid - 1;
           }
           else{
             l = mid + 1;
           }
        }
        else{
            if(nums[mid] < target && nums[r] >= target){
               l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,0,1,1,1};
    int target = 0;

    cout << search(nums, target) << "\n";
}