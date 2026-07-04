#include<bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

bool isValid(vector<vector<char>>&grid, int i, int j){
     if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1'){
        return true;
     }
     return false;
}
void DFS(vector<vector<char>>& grid, int i, int j){
     grid[i][j] = '0';
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(grid, next_i, next_j)){
            DFS(grid, next_i, next_j);
        }
     }
}
int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                DFS(grid, i, j);
                count++;
            }
        }
    }
    return count;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<char>> grid = {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'}
};
 cout << numIslands(grid) << "\n";
}