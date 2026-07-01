
#include<bits/stdc++.h>
using namespace std;
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
   unordered_map<int, int>mp;
   int row = matrix.size();
   int col = matrix[0].size();
   for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
         int idx = i - j;
         if(mp.find(idx) == mp.end()){
             mp[idx] = matrix[i][j];
         }
         else if(mp[idx] != matrix[i][j]){
            return false;
         }
      }
   }
   return true;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
    {1, 2, 3, 4},
    {5, 1, 2, 3},
    {9, 5, 1, 2}
};
 cout << isToeplitzMatrix(matrix) << "\n";
}

//  0 0  0 1  0 2   0 3
//  1 0  1 1  1 2   1 3
//  2 0  2 1  2 2   2 3
//  3 0  3 1  3 2   3 3

// 

