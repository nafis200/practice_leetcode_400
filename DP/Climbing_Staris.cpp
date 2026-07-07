
#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
  vector<int>dp(n + 1, 0);
//   f(i - 1) + f(i - 2);

  dp[0] = 1;
  dp[1] = 1;
  for(int i = 2; i <= n; i++){
     dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 2;
    cout << climbStairs(n) << "\n";
}