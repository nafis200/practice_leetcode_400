
#include<bits/stdc++.h>
using namespace std;

//  7 4 3 1 10
//  1 3 4 7 10  

void insertSort(vector<int>&nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        int key = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > key){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {7, 4, 3, 1, 10};
    insertSort(nums);
    for(auto i : nums){
        cout << i << " ";
    }
}