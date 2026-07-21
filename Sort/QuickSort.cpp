#include<bits/stdc++.h>
using namespace std;

// 7, 4, 3, 1, 10

int QuickSort(vector<int>&nums, int low,int high){
    int i = low;
    int pivot = high;
    for(int j = low; j < high; j++){
        if(nums[j] < nums[pivot]){
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[pivot]);
    return i;
}


void Partition(vector<int>&nums, int low,int high){
     if(low < high){
        int partition = QuickSort(nums, low, high);
        Partition(nums, low, partition - 1);
        Partition(nums, partition + 1, high);
     }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     
}