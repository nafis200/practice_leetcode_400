
#include<bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

// Time o(n * m) space o(n * m)

vector<vector<int>>vis;
bool isValid(vector<vector<int>>& matrix, int i, int j, int next_i, int next_j){
  if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && matrix[next_i][next_j] > matrix[i][j]){
      return true;
  }
  return false;
}

int DFS(vector<vector<int>>& matrix, int i, int j){
    int count = 1;
    if(vis[i][j] != -1){
        return vis[i][j];
    }
    for(int k = 0; k < 4; k++){
        int next_i = dx[k] + i;
        int next_j = dy[k] + j;
        if(isValid(matrix, i, j, next_i, next_j)){
            count = max(count, DFS(matrix, next_i, next_j) + 1);
        }
    }
    return vis[i][j] = count;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
   n = matrix.size();
   m = matrix[0].size();
   int ans = 0;
   vis.assign(n, vector<int>(m, -1));
   for(int i = 0; i < n; i++){
     for(int j = 0; j < m; j++){
        ans = max(ans, DFS(matrix, i, j));
     }
   }
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
    {9, 9, 4},
    {6, 6, 8},
    {2, 1, 1}
};
 cout << longestIncreasingPath(matrix) << "\n";
}