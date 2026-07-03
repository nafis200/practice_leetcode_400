
#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
  int n = s.size();
  int sign = 1;
  long long number = 0;
  int i = 0;
  while (i < n && s[i] == ' ') {
    i++;
  }
  if (i == n) {
    return 0;
  }
  if (s[i] == '-') {
    sign = -1;
    i++;
  } else if (s[i] == '+') {
    sign = 1;
    i++;
  }

  for (i; i < n; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      int x = s[i] - '0';
      // INT_MAX =  2147483647
      // INT_MIN = -2147483648
      if (sign == 1) {
        if (number > INT_MAX / 10 || (number == INT_MAX / 10 && x > 7))
          return INT_MAX;
      } else {
        if (number > INT_MAX / 10 || (number == INT_MAX / 10 && x > 8))
          return INT_MIN;
      }

      number = number * 10 + x;
    } else {
      break;
    }
  }

  long long ans = sign * number;

  if (ans > INT_MAX) return INT_MAX;

  if (ans < INT_MIN) return INT_MIN;

  return (int)ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = " -042";
  int ans = myAtoi(s);
  cout << ans << "\n";
}