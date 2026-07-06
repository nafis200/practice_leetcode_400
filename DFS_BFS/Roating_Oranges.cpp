
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
bool isValid(vector<vector<int>>& grid, int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
    return true;
  }
  return false;
}
int orangesRotting(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  int steps = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        q.push({i, j});
      }
    }
  }
  int sz = 0;
  while (!q.empty()) {
    sz = q.size();
    bool ok = false;
    while (sz--) {
      auto x = q.front();
      q.pop();
      int i = x.first;
      int j = x.second;
      for (int k = 0; k < 4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if (isValid(grid, next_i, next_j)) {
          grid[next_i][next_j] = 2;
          q.push({next_i, next_j});
          ok = true;
        }
      }
    }
    if (ok) {
      steps++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        return -1;
      }
    }
  }
  return steps;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {
    {2, 0, 1},
    {0, 1, 0},
    {0, 1, 1}
};
 int ans = orangesRotting(grid);
 cout << ans << "\n";
}