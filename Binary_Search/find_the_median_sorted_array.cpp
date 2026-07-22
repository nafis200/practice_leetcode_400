
#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1 > n2){
        swap(nums1, nums2);
        swap(n1, n2);
    } 
    int l = 0, r = n1;
    int mid = 0;
    while(l <= r){
        mid = (l + r) / 2;
        int cut1 = mid;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if(cut1 > 0){
            l1 = nums1[cut1 - 1];
        }
        if(cut1 < n1){
            r1 = nums1[cut1];
        }
        if(cut2 > 0){
            l2 = nums2[cut2 - 1];
        }
        if(cut2 < n2){
            r2 = nums2[cut2];
        }
        if(l1 <= r2 && l2 <= r1){
            int sum = n1 + n2;
            if(sum % 2 == 0){
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else{
                return max(l1, l2);
            }
        }
        if(l1 > r2){
            r = mid - 1;
        }
        else{
           l = mid + 1;
        }
    }
    return 0.0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}