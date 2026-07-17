
#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    nums.push_back(0);
    int cnt = 0;
    int ans = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == 0){
           ans = max(ans, cnt);
           cnt = 0;
        }
        else{
            cnt++;
        }
    }
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1,1,0,1,1,1};
  
}


