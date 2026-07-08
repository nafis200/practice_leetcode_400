
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> memo;
int dp(int i, int j, string& s, string& p) {
  if (i == n && j == m) {
    return 1;
  }
  if (i == n) {
    for (int k = j; k < m; k++) {
      if (p[k] != '*') {
        return false;
      }
    }
    return true;
  }
  if(j == m){
    return false;
  }
  if(memo[i][j] != -1){
    return memo[i][j];
  }
  bool ans = 0;
  if(s[i] == p[j] || p[j] == '?'){
     ans = dp(i + 1, j + 1, s, p);
  }
  if(p[j] == '*'){
     ans = ans | dp(i + 1, j, s, p) | dp(i, j + 1, s, p);
  }
  return memo[i][j] = ans;
}
bool isMatch(string s, string p) {
  n = s.size();
  m = p.size();
  memo.assign(n, vector<int>(m, -1));
  int ans = dp(0, 0, s, p);
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "aa", p = "*";
  bool ans = isMatch(s, p);
  cout << ans << "\n";
}