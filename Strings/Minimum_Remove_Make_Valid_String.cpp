
#include <bits/stdc++.h>
using namespace std;
// ))((
string minRemoveToMakeValid(string s) {
  int n = s.size();
  vector<bool> vis(n, false);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else if (s[i] == ')') {
      if (st.empty()) {
        vis[i] = true;
      } else {
        st.pop();
      }
    }
  }
  while (!st.empty()) {
    vis[st.top()] = true;
    st.pop();
  }
  string result = "";
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      result += s[i];
    }
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "))((";
  cout << minRemoveToMakeValid(s) << "\n";
}