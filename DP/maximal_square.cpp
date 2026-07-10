
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;
int maximalSquare(vector<vector<char>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  memo.assign(n, vector<int>(m, 0));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == '0') {
        continue;
      }
      if (i == 0 || j == 0) {
        memo[i][j] = 1;
        ans = max(ans, memo[i][j]);
      } else {
        int top = memo[i - 1][j];
        int left = memo[i][j - 1];
        int corner = memo[i - 1][j - 1];
        int mn = min({top, left, corner});

        memo[i][j] = mn + 1;

        ans = max(ans, memo[i][j]);
      }
    }
  }
  return 1LL * ans * ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

//  1 1 1
//  1 1 1
//  1 1 1
