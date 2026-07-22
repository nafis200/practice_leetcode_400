
#include<bits/stdc++.h>
using namespace std;
// 4,5,6,7,8,0,1,2
//         l m   r
// 4 + 7
//  5

//  1 2 3 4 5 6 7 8 9
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid = 0, ans = -1;

    while(l <= r){
        mid = (l + r) / 2;
        if(nums[mid] == target){
            ans = mid;
            break;
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
    vector<int>nums = {4,5,6,7,0,1,2};

    int target = 0;

    cout << search(nums, target) << "\n";
}