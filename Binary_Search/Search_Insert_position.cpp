
#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int ans = -1;
    int l = 0, r = nums.size() - 1;

    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] >= target){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(ans == -1){
        ans = nums.size();
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}