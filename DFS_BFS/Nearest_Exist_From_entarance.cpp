
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
bool isValid(vector<vector<char>>& grid, int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.') {
    return true;
  }
  return false;
}
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
  n = maze.size();
  m = maze[0].size();

  //  0  0  n - 1  m - 1
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {entrance[0], entrance[1]}});
  maze[entrance[0]][entrance[1]] = '+';
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    int cost = x.first;
    int i = x.second.first;
    int j = x.second.second;

    if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
         if(!(i == entrance[0] && j == entrance[1])){
            return cost;
         }
    }
    //  1 0      1 2
    for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(maze,next_i, next_j)){
            q.push({cost + 1, {next_i, next_j}});
            maze[next_i][next_j] = '+';
        }
    }
  }
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<char>> maze = {
      {'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
      vector<int>entrance = {1, 0};
      int ans = nearestExit(maze, entrance);
      cout << ans << "\n";
}