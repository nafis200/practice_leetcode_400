
#include <bits/stdc++.h>
using namespace std;

 int maxArea(vector<int>& height) {
     int l = 0, r = height.size() - 1;
     int mn = 0;
     int ans = 0;
     while(l < r){
         int w = r - l;
         int h = min(height[l], height[r]);
         ans = max(ans, w * h);
         if(height[l] <= height[r]){
             l++;
         }
         else{
            r--;
         }
     }
     return ans;
 }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1,8,6,2,5,4,8,3,7};

  cout << maxArea(nums) << "\n";
 
}


