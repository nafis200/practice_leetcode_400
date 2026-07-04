
#include<bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
bool isValid(vector<vector<char>>&board, int i, int j){
     if(i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O'){
        return true;
     }
     return false;
}
void DFS(vector<vector<char>>& board, int i, int j){
     board[i][j] = 'A';
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(board, next_i, next_j)){
            DFS(board, next_i, next_j);
        }
     }
}
void solve(vector<vector<char>>& board) {
     n = board.size();
     m = board[0].size();
     for(int i = 0; i < m; i++){
         if(board[0][i] == 'O'){
            DFS(board, 0, i);
         }
         if(board[n - 1][i] == 'O'){
            DFS(board, n - 1, i);
         }
     }
     for(int i = 0; i < n; i++){
         if(board[i][0] == 'O'){
            DFS(board, i, 0);
         }
         if(board[i][m - 1] == 'O'){
            DFS(board, i, m - 1);
         }
     }
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(board[i][j] == 'A'){
             board[i][j] = 'O';
           }
           else{
             board[i][j] = 'X';
           }
        }
     }
     
     
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<char>> board = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'O', 'X', 'X'}
};
 solve(board);
 for(auto v : board){
    cout << "[";
    for(auto i : v){
        cout << i << " ";
    }
    cout << "]\n";
 }
}