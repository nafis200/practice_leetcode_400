
#include <bits/stdc++.h>
using namespace std;

//  1 1 2 2
//  2 2

 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int>ans;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int l = 0, r = 0;
    while(l < n1 && r < n2){
        if(nums1[l] == nums2[r]){
            ans.push_back(nums1[l]);
            l++;
            r++;
        }
        else if(nums1[l] < nums2[r]){
            l++;
        }
        else{
            r++;
        }
    }
    return ans;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>nums = {1,2,2,1};
  vector<int>nums1 = {2, 2};
  vector<int>ans = intersect(nums, nums1);
  for(auto i : ans){
    cout << i << " ";
  }
}



