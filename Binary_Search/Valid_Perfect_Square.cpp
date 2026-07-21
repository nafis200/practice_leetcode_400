#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int num) {
    int l = 1, r = num, ans = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(1LL * mid * mid <= num){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }  
    if(ans * ans == num){
        return true;
    }
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num = 16;
    cout << isPerfectSquare(num) << "\n";
}