
// #include <bits/stdc++.h>
// using namespace std;
// int n, m;
// vector<vector<int>>memo;
// int dp(int i, int j,vector<vector<int>>& grid){
//     if(i == n - 1 && j == m - 1){
//         return grid[i][j];
//     }
//     if(i == n || j == m){
//         return 100000;
//     }
//     if(memo[i][j] != -1){
//         return memo[i][j];
//     }
//     int ans = INT_MAX;
//     int ans1 = INT_MAX;
//     ans = dp(i + 1, j, grid) + grid[i][j];
//     ans1 = dp(i, j + 1, grid) + grid[i][j];
//     return memo[i][j] = min(ans, ans1);
// }
// int minPathSum(vector<vector<int>>& grid) {
//     n = grid.size();
//     m = grid[0].size();
//     memo.assign(n, vector<int>(m, -1));
//     return dp(0, 0, grid);
// }
// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

//   int ans = minPathSum(grid);
//   cout << ans << "\n";
// }

#include <bits/stdc++.h>
using namespace std;
int n, m;
bool isValid(int i, int j) {
  if (i <= n - 1 && j <= m - 1) {
    return true;
  }
  return false;
}
int minPathSum(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

  dist[0][0] = grid[0][0];
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      q;

  q.push({grid[0][0], {0, 0}});
  while (!q.empty()) {
    auto x = q.top();
    q.pop();
    int cost = x.first;
    int i = x.second.first;
    int j = x.second.second;
    if (i == n - 1 && j == m - 1) {
      return cost;
    }
    int next_i = i + 1;
    int next_y = j + 1;
    if (isValid(next_i, j)) {
      int newCost = cost + grid[next_i][j];

      if (dist[next_i][j] > newCost) {
        dist[next_i][j] = newCost;
        q.push({newCost, {next_i, j}});
      }
    }

    if (isValid(i, next_y)) {
      int newCost = cost + grid[i][next_y];

      if (dist[i][next_y] > newCost) {
        dist[i][next_y] = newCost;
        q.push({newCost, {i, next_y}});
      }
    }
  }
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << minPathSum(grid) << "\n";
}