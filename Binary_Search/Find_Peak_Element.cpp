
#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& nums) {
    int ans = 0;
    int l = 0, r = nums.size() - 1;
    int mid = 0;
    while(l < r){
        mid = (l + r) / 2;
        if(nums[mid] < nums[mid + 1]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }   
    return l;
}

//   1 2 3 1 4 5 6
//   0 1 2 3 4 5 6
//         


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,2,3,1,4,5,6};

    cout << findPeakElement(nums) << "\n";
}

// 1

// 1

//  1 2 3
//  4 5 6

// r1 = 1  r2 = 4