
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

bool isValid(vector<vector<int>>& grid, int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m) {
    if (grid[i][j] != -1) {
      return true;
    }
  }
  return false;
}
void islandsAndTreasure(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    int i = x.first;
    int j = x.second;
    for (int k = 0; k < 4; k++) {
      int next_i = i + dx[k];
      int next_j = j + dy[k];
      if (isValid(grid, next_i, next_j)) {
        if (grid[i][j] != INT_MAX && grid[i][j] + 1 < grid[next_i][next_j]) {
          grid[next_i][next_j] = grid[i][j] + 1;
          q.push({next_i, next_j});
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> rooms = {{2147483647, -1, 0, 2147483647},
                               {2147483647, 2147483647, 2147483647, -1},
                               {2147483647, -1, 2147483647, -1},
                               {0, -1, 2147483647, 2147483647}};

    islandsAndTreasure(rooms);

    for(auto v : rooms){
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
}