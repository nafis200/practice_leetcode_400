

#include<bits/stdc++.h>
using namespace std;
 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     int l = 0, r = arr.size() - k;
     int mid = 0;
     while(l < r){
        mid = (l + r) / 2;
        if(x - arr[mid] > arr[mid + k] - x){
            l = mid + 1;
        }
        else{
            r = mid;
        }
     }
     vector<int>ans;
     for(int i = l; i < l + k; i++){
         ans.push_back(arr[i]);
     }
     return ans;
 }

//   1 2 3 4 5

//  1 
//        5 

// x - 1    <    5 - x

// x = 5
// k = 4

//  l = 0   to   l = 2

//  mid = 1   

//  1 1 2 3
//  1 2 3 4
//  2 3 4 5

int32_t main(){
    vector<int>arr = {1,2,3,4,5};
    int k = 4, x = 3;
    vector<int>ans = findClosestElements(arr, k, x);
}

