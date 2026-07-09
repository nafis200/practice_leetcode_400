
#include <bits/stdc++.h>
using namespace std;
int n, m, w;
string x, y, z;
vector<vector<int>> memo;

// s1 = a
// s2 = b
// s3 = ab
// s3 = ba

bool dp(int i, int j) {
  if (i == n && j == m) {
    return true;
  }
  if (i > n || j > m) {
    return false;
  }
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  int k = i + j;
  bool ans = false;
  if(i < n && x[i] == z[k]){
     ans |= dp(i + 1, j);
  }
  if(j < m && y[j] == z[k]){
     ans |= dp(i, j + 1);
  }
  return memo[i][j] = ans;
}

bool isInterleave(string s1, string s2, string s3) {
  n = s1.size();
  m = s2.size();
  w = s3.size();
  x = s1;
  y = s2;
  z = s3;
  memo.assign(n + 1, vector<int>(m + 1, -1));
  if (n + m != w) {
    return false;
  }
  return dp(0, 0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
}