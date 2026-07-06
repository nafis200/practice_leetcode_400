#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int numSquares(int n) {
   dp.assign(n + 1, INT_MAX);
   dp[0] = 0;
   for(int i = 1; i <= n; i++){
     for(int j = 1; j * j <= i; j++){
        dp[j] = min(dp[i], dp[i - j] + 1);
     }
   }
   return dp[n];
}




int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 12;
    cout << numSquares(n);
}

//  100 * 100