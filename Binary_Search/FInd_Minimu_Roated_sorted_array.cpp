
//  0 1 2 3 4 5 6 7

//  7 0 1 2 3 4 5 6

#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    int ans = 0;
    int mid = 0;
    
    while(l < r){
        mid = (l + r) / 2;
        if(nums[mid] <= nums[r]){
            r = mid;
            ans = nums[mid];
        }
        else{
            l = mid + 1;
        }
    }

    return nums[l];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    vector<int>nums={4,5,6,7,0,1,2};
}