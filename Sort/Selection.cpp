
//  7 4 3 1 10

#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>&nums){
   int n = nums.size();
   for(int i = 0; i < n; i++){
       int mn = INT_MAX;
       int k = -1;
       for(int j = i + 1; j < n; j++){
           if(nums[i] > nums[j]){
                if(mn > nums[j]){
                    mn = nums[j];
                    k = j;
                }
           }
       }
       if(k != -1){
          swap(nums[i], nums[k]);
       }
   }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {7, 4, 3, 1, 10};
    SelectionSort(nums);
    for(auto i : nums){
        cout << i << " ";
    }
}