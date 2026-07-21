#include<bits/stdc++.h>
using namespace std;

int arrangeCoins(long long n) {
    long long l = 0, r = n;
    long long ans = 0;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        long long equation = (1LL * mid * (mid + 1)) / 2;
        if(equation <= n){
             ans = mid;
             l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return (int)ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n = 5;
    cout << arrangeCoins(n) << "\n";
}