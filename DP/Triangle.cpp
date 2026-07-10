
#include <bits/stdc++.h>
using namespace std;

// Time o(n^2)

// vector<vector<int>>memo;
// int n, m;
// int dp(int i, int j, vector<vector<int>>& triangle){
   
//    if(i == n - 1){
//      return triangle[i][j];
//    }
//    if(memo[i][j] != INT_MAX){
//      return memo[i][j];
//    }
//    int ans = 0;
//    int ans1 = 0;
//    ans = dp(i + 1, j, triangle) + triangle[i][j];
//    ans1 = dp(i + 1, j + 1, triangle) + triangle[i][j];
//    return memo[i][j] = min(ans, ans1);
// }
// int minimumTotal(vector<vector<int>>& triangle) {
//     n = triangle.size();
//     m = triangle[n - 1].size();
//     memo.assign(n, vector<int>(m, INT_MAX));
//     return dp(0, 0,triangle);
// }

int minimumTotal(vector<vector<int>>& triangle) {

    int n = triangle.size();
    vector<int>memo = triangle[n - 1];
    for(int i = n - 2; i >= 0; i--){
      for(int j = 0; j <= i; j++){
        int mn = min(memo[j], memo[j + 1]);
        memo[j] = mn + triangle[i][j];
      }
    }
    return memo[0];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  cout << minimumTotal(triangle) << "\n";
}