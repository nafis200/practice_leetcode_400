
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>memo;

int dp(int i, vector<int>& cost){
      if(i == n){
        return 0;
      }
      if(i > n){
         return 0;
      }
      if(memo[i] != -1){
        return memo[i];
      }
      int ans = 0;
      ans = dp(i + 1, cost) + cost[i];
      ans = min(ans, dp(i + 2, cost) + cost[i]);

      return memo[i] = ans;
}

int minCostClimbingStairs(vector<int>& cost) {
    n = cost.size();
    memo.assign(n + 1, -1);
    int ans = dp(0, cost);
    int ans1 = dp(1, cost);
    return min(ans, ans1);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>cost = {10, 15, 20};
    int ans = minCostClimbingStairs(cost);
    cout << ans << "\n";
}