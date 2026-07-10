
#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
  int n = s.size();
  int odd = 0, even = 0;
  for (int center = 0; center < n; center++) {
    int l = center;
    int r = center;
    while (l >= 0 && r < n && s[l] == s[r]) {
      odd++;
      l--;
      r++;
    }
  }

  for (int center = 1; center < n; center++) {
    int l = center - 1;
    int r = center;
    while (l >= 0 && r < n && s[l] == s[r]) {
      even++;
      l--;
      r++;
    }
  }
  return odd + even;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "aaa";
  cout << countSubstrings(s) << "\n";
}

// aaa
// 1 2 1
// 1 1