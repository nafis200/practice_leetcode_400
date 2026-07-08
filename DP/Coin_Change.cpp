#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
int n;

// int dp(vector<int>& coins, int i, int amount){
//     if(i == n){
//         if(amount == 0){
//             return 0;
//         }
//         return INT_MAX - 2;
//     }
//     if(amount < 0){
//         return INT_MAX - 2;
//     }
//     if(memo[i][amount] != -1){
//         return memo[i][amount];
//     }
//     int ans = INT_MAX;
//     ans = dp(coins, i + 1, amount);
//     ans = min(ans, dp(coins, i, amount - coins[i]) + 1);
//     return memo[i][amount] = ans;
// }

// int coinChange(vector<int>& coins, int amount) { 

//     n = coins.size();
//     memo.assign(n, vector<int>(amount + 1, -1));
//     int ans = dp(coins, 0, amount);
//     if(ans == INT_MAX - 2){
//         return -1;
//     }
//     return ans; 
// }

int coinChange(vector<int>& coins, int amount) { 

    n = coins.size();
    memo.assign(n + 1, vector<int>(amount + 1, INT_MAX - 2));
    memo[n][0] = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= amount; j++){
            memo[i][j] = memo[i + 1][j];
            if(j - coins[i] >= 0){
                memo[i][j] = min(memo[i][j], memo[i][j - coins[i]] + 1);
            }
        }
    }
    if(memo[0][amount] == INT_MAX - 2){
        return -1;
    }
    return memo[0][amount];
    
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>coins = {1, 2, 5};
  int amount = 11;
  int ans = coinChange(coins, amount);
  cout << ans << "\n";
}