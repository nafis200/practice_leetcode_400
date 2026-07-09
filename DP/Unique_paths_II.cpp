
#include<bits/stdc++.h>
using namespace std;
int n;
int m;
vector<vector<int>>memo;

int dp(int i, int j,vector<vector<int>>& obstacleGrid){
    if(i == n - 1 && j == m - 1){
        return 1;
    }
    if(i == n || j == m){
        return 0;
    }
    if(obstacleGrid[i][j]){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    int ans = dp(i + 1, j,obstacleGrid);
    ans += dp(i, j + 1,obstacleGrid);
    return memo[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    n = obstacleGrid.size();
    m = obstacleGrid[0].size();
    memo.assign(n, vector<int>(m, -1));
    if(obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1){
       return 0;
    }
    return dp(0, 0, obstacleGrid);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> obstacleGrid = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
};
 cout << uniquePathsWithObstacles(obstacleGrid) << "\n";
}