
#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
  int ans = 0;
  stack<int> st;
  int n = heights.size();
  for (int i = 0; i < n; i++) {
    if (st.empty()) {
      st.push(i);
      continue;
    }
    while (!st.empty() && heights[st.top()] > heights[i]) {
      int r = i - 1;
      int x = st.top();
      st.pop();
      int l = 0;
      if (st.empty()) {
        l = -1;
      } else {
        l = st.top();
      }
      ans = max(ans, (r - l) * heights[x]);
    }
    st.push(i);
  }

  while (!st.empty()) {
    int r = n - 1;
    int x = st.top();
    st.pop();
    int l = 0;
    if (st.empty()) {
      l = -1;
    } else {
      l = st.top();
    }
    ans = max(ans, (r - l) * heights[x]);
  }

  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  int ans = largestRectangleArea(heights);
  cout << ans << "\n";
}