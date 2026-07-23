
#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
  unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};
  int n = s.size();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      sum += mp[s[i]];

    } else {
      if (mp[s[i]] >= mp[s[i + 1]]) {
        sum += mp[s[i]];
      } else {
        sum = sum + (mp[s[i + 1]] - mp[s[i]]);
        i++;
      }
    }
  }
  return sum;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "MCMXCIV";
  cout << romanToInt(s) << "\n";
}