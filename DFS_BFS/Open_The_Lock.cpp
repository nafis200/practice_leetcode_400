
#include <bits/stdc++.h>
using namespace std;
int openLock(vector<string>& deadends, string target) {
  unordered_set<string> st(deadends.begin(), deadends.end());
  unordered_set<string> vis;
  if (st.count("0000")) {
    return -1;
  }
  queue<pair<string, int>> q;
  q.push({"0000", 0});
  vis.insert("0000");
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    string s = x.first;
    int step = x.second;
    if (s == target) {
      return step;
    }
    for (int k = 0; k < 4; k++) {
      string original = s;
      if (s[k] == '9') {
        s[k] = '0';
      } else {
        s[k] = s[k] + 1;
      }
      if (!vis.count(s) && !st.count(s)) {
        q.push({s, step + 1});
        vis.insert(s);
      }
      s = original;
      if (s[k] == '0') {
        s[k] = '9';
      } else {
        s[k] = s[k] - 1;
      }
      if (!vis.count(s) && !st.count(s)) {
        q.push({s, step + 1});
        vis.insert(s);
      }
      s = original;
    }
  }
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};

  string target = "0202";
  int ans = openLock(deadends, target);
  cout << ans << "\n";
}