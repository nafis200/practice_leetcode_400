
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
int swimInWater(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({grid[0][0], 0, 0});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int cost = x[0];
        int i = x[1];
        int j = x[2];
        if(i == n - 1 && j == m - 1){
            return cost;
        }
        for(int k = 0; k < 4; k++){
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            if(isValid(grid, next_i, next_j)){
                int newCost = max(cost, grid[next_i][next_j]);
                pq.push({newCost, next_i, next_j});
                grid[next_i][next_j] = -1;
            }
        }
    }
    return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 1, 2, 3, 4},
                              {24, 23, 22, 21, 5},
                              {12, 13, 14, 15, 16},
                              {11, 17, 18, 19, 20},
                              {10, 9, 8, 7, 6}};
}