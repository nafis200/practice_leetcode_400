
#include<bits/stdc++.h>
using namespace std;

// n * m * (n + m)

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    bool col = false;
    bool row = false;
    for(int i = 0; i < m; i++){
        if(matrix[0][i] == 0){
           col = true;
        }
    }
    for(int i = 0; i < n; i++){
        if(matrix[i][0] == 0){
            row = true;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < m; i++){
        if(matrix[0][i] == 0){
           for(int j = 1; j < n; j++){
             matrix[j][i] = 0;
           }
        }
    }
    for(int i = 1; i < n; i++){
         if(matrix[i][0] == 0){
            for(int j = 1; j < m; j++){
                matrix[i][j] = 0;
            }
         }
    }
    if (col) {
    for (int i = 0; i < m; i++) {
      matrix[0][i] = 0;
    }
  }
  if (row) {
    for (int i = 0; i < n; i++) {
      matrix[i][0] = 0;
    }
  }
}

//  1 0 1
//  1 0 1
//  1 1 1

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
};
setZeroes(matrix);
 for(auto v : matrix){
    cout << "[";
    for(auto i : v){
        cout << i << " ";
    }
    cout << "]\n";
 }
}