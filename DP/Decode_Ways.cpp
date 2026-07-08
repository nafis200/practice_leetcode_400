
#include <bits/stdc++.h>
using namespace std;
vector<int> memo;
int n;
int dp(int i, string s) {
  if (i == n) {
    return 1;
  }
  if (s[i] == '0') {
    return 0;
  }
  if (memo[i] != -1) {
    return memo[i];
  }
  int ans = 0;
  int num = 0;
  ans = dp(i + 1, s);
  if(i + 1 < n){
     num = (s[i] - '0') * 10 + (s[i + 1] - '0');
     if(num >= 10 && num <=26){
         ans += dp(i + 2, s);
     }
  }
  return memo[i] = ans;
}

// 2 2 6
//  0 6
int numDecodings(string s) {
  n = s.size();
  memo.assign(n, -1);
  int ans = dp(0, s);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "06";
  cout << numDecodings(s) << "\n";
}

// 226
//  2 2 6
//  2  26
//  22 6

//  20 6
