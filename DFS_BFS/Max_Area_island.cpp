
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

bool isValid(vector<vector<int>>& grid, int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m) {
    if (grid[i][j] != 0) {
      return true;
    }
  }
  return false;
}
int DFS(vector<vector<int>>& grid, int components, int i, int j){
    components = 1;
    grid[i][j] = 0;
    for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(grid, next_i, next_j)){
            components += DFS(grid,components, next_i, next_j);
        }
    }
    return components;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  int ans = INT_MIN;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(grid[i][j]){
            ans = max(ans, DFS(grid,0,i, j));
        }
    }
  }
  if(ans == INT_MIN){
    ans = 0;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    int ans = maxAreaOfIsland(grid);
    cout << ans << "\n";
}