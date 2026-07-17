
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0;
    int n = nums.size();
    for(i; i < n; i++){
        if(nums[i] == val){
            break;
        }
    }
    int j = i + 1;
    for(j; j < n; j++){
        if(nums[j] != val){
            swap(nums[i], nums[j]);
            i++;
        }
    }
    return i;
}

// 0,1,3,0,4,2,2,2

//   i = 4

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0,1,2,2,3,0,4,2};
  int n = removeElement(nums, 2);
  cout << n << "\n";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
}

// 0 1 0 3 12

//  1 3 0 0 12
