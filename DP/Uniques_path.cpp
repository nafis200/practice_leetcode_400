
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;
int x, y;
int dp(int i, int j){
    if(i == x || j == y){
        return 0;
    }
    if(i == x - 1 && j == y - 1){
        return 1;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = 0;
    ans = dp(i + 1, j) + dp(i, j + 1);
    return memo[i][j] = ans;
}

int uniquePaths(int m, int n) {
    x = m;
    y = n;
    memo.assign(m, vector<int>(n, -1));
    int ans = dp(0, 0);
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << "\n";
}