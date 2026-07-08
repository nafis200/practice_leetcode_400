
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> memo;
int dp(int i, int j, string& s, string& p) {
  if (i == n && j == m) {
    return true;
  }
  if (i == n) {
    if(j + 1 < m && p[j + 1] == '*'){
        return dp(i, j + 2, s, p);
    }
    return false;
  }
  if (j == m) {
    return i == n;
  }
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  bool match = false;
  if (i < n && (s[i] == p[j] || p[j] == '.')) {
    match = true;
  }
  bool ans = false;
  if (j + 1 < m && p[j + 1] == '*') {
    ans = dp(i, j + 2, s, p);
    if (match) {
      ans = ans | dp(i + 1, j, s, p);
    }
  } else {
    if (match) {
      ans = ans || dp(i + 1, j + 1, s, p);
    }
  }
  return memo[i][j] = ans;
}
bool isMatch(string s, string p) {
  n = s.size();
  m = p.size();
  memo.assign(n, vector<int>(m, -1));
  return dp(0, 0, s, p);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}