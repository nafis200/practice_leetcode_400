#include<bits/stdc++.h>
using namespace std;
int n, m;
int dx[8] = {0, -1, 0, 1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
bool isValid(vector<vector<int>>& grid, int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 0){
        return true;
    }
    return false;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vector<vector<int>>dis(n, vector<int>(m, INT_MAX));
    if(grid[0][0] == 1){
        return -1;
    }
    dis[0][0] = 1;
    queue<pair<int,int>>q;
    q.push({0, 0});
    
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int i = x.first;
        int j = x.second;
        for(int k = 0; k < 8; k++){
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            if(isValid(grid, next_i, next_j)){
                if(dis[i][j] + 1 < dis[next_i][next_j]){
                    dis[next_i][next_j] = dis[i][j] + 1;
                    q.push({next_i, next_j});
                }
            }
        }
    }
   if(dis[n - 1][m - 1] != INT_MAX){
     return dis[n - 1][m - 1];
   }
   return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {
    {0, 0, 0},
    {1, 1, 0},
    {1, 1, 0}
};
}