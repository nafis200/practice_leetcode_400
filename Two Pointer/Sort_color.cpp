
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    int mid = 0;
    while(mid <= r){
        if(nums[mid] == 0){
            swap(nums[l], nums[mid]);
            l++;
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[mid], nums[r]);
            r--;
        }
        else{
           mid++;
        }
    }
}

//  2 0 1
//  1 0 2

//  1 1 0 2

//  0

// 2 0 2 1 1 0

// 0 = mid = 2

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>nums = {2,0,2,1,1,0};


  sortColors(nums);
  for(auto i : nums){
    cout << i << " ";
  }
}


//  1 0 2 0 0 1

//  0 0 0 1 2 1

