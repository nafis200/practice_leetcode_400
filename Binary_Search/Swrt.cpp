
#include<bits/stdc++.h>
using namespace std;
int mySqrt(int x) {
    int l = 0, r = x;
    int ans = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(1LL * mid * mid <= x){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }   
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}