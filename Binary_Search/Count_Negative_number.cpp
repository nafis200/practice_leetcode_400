#include<bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    int row = 0, col = m - 1;
    while(row < n && col >= 0){
         if(grid[row][col] < 0){
             ans += n - row;
             col--;
         }
         else{
             row++;
         }
    }
    return ans;
}

//  7 4 3 1 10

//  7 4 3 1 10


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {
    {4, 3, 2, -1},
    {3, 2, 1, -1},
    {1, 1, -1, -2},
    {-1, -1, -2, -3}
};

cout << countNegatives(grid) << "\n";
    
}