
#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    int mid = 0;
    while(l < r){
        mid = (l + r) / 2;
        if(nums[mid] == nums[mid ^ 1]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return nums[l];
}




//  0  1
//  2  3
//  4  5

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums) << "\n";
}

// 0  1  2  3  4  5  6  7  8  
// 1  1  2  2  3  3  4  5  5