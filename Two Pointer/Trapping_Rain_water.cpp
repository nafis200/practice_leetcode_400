
// 0,1,0,2,1,0,1,3,2,1,2,1

// left right
// mn = 0
// 
//
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height){
   int left_max = height[0];
   int right_max = height[height.size() - 1];
   int water = 0;
   int l = 0, r = height.size() - 1;
   while(l < r){
    if(height[l] <= height[r]){
        if(height[l] > left_max){
            left_max = height[l];
        }
        else{
            water += left_max - height[l];
        }
        l++;
    }
    else{
        if(height[r] > right_max){
            right_max = height[r];
        }
        else{
            water += right_max - height[r];
        }
        r--;
    }
   } 
   return water;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>heights = {0,1,0,2,1,0,1,3,2,1,2,1};
  int ans = trap(heights);
  cout << ans << "\n";
 
}


