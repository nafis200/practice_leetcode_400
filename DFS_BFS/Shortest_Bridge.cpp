
//  0 1 1
//  0 0 0
//  0 0 1

#include<bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

bool isValid(vector<vector<int>>&grid, int i, int j){
     if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1){
        return true;
     }
     return false;
}
void DFS(vector<vector<int>>& grid, int i, int j,queue<pair<int,pair<int,int>>>&q){
     grid[i][j] = -1;
     q.push({0, {i, j}});
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(grid, next_i, next_j)){
            DFS(grid, next_i, next_j,q);
        }
     }
}
int shortestBridge(vector<vector<int>>& grid){
   queue<pair<int,pair<int,int>>>q;
   n = grid.size();
   m = grid[0].size();
   bool found = false;
   for(int i = 0; i < n; i++){
     for(int j = 0; j < m; j++){
        if(grid[i][j] == 1){
            DFS(grid,i, j, q);
            found = true;
            break;
        }
     }
     if(found){
        break;
     }
   }   
   while(!q.empty()){
     auto x = q.front();
     q.pop();
     int cost = x.first;
     int i = x.second.first;
     int j = x.second.second;
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && grid[next_i][next_j] != -1){
             if(grid[next_i][next_j] == 1){
                return cost;
             }
             q.push({cost + 1, {next_i, next_j}});
             grid[next_i][next_j] = -1;
        }
     }
      
   }
   return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {
    {0, 1, 1},
    {0, 0, 0},
    {0, 0, 1}
};
 int ans = shortestBridge(grid);
 cout << ans << "\n";
}