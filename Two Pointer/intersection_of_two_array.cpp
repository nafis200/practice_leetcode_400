
#include <bits/stdc++.h>
using namespace std;

//  4 9 5
//  4 4 8 8 9

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int n1 = nums1.size();
  int n2 = nums2.size();

  vector<int> ans;

  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (nums1[i] == nums2[j]) {
      int x = nums1[i];
      ans.push_back(nums1[i]);
      while (i < n1 && nums1[i] == x) {
        i++;
      }
      while (j < n2 && nums2[j] == x) {
        j++;
      }
    } else if (nums1[i] > nums2[j]) {
      j++;
    } else {
      i++;
    }
  }
  return ans;
}
};

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ans;
    vector<bool>vis(1002, false);
    for(auto i : nums1){
         vis[i] = true;
    }

    for(auto i : nums2){
        if(vis[i] == true){
            ans.push_back(i);
            vis[i] = false;
        }
    }
    return ans;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {4, 9, 5}, nums1 = {9, 4, 9, 8, 4};

  vector<int> ans = intersection(nums, nums1);
  for (auto i : ans) {
    cout << i << " ";
  }
}
