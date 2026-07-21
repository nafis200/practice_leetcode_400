#include<bits/stdc++.h>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    int ans = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(mid - 1 >= 0 && arr[mid] < arr[mid - 1]){
             ans = mid - 1;
             r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}
int32_t main(){
    vector<int>v = {0,2,1,0};

    // l = 0, r = 3
    //  2 3
    //  

    cout << peakIndexInMountainArray(v) << "\n";
}