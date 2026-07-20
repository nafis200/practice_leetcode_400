#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
  int n = temperatures.size();
  vector<int> ans(n, 0);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    int x = temperatures[i];
    while (!st.empty() && temperatures[st.top()] <= x) {
      st.pop();
    }
    if (!st.empty()) {
      int ans1 = st.top() - i;
      ans[i] = ans1;
    }
    if (st.empty() || x < temperatures[st.top()]) {
      st.push(i);
    }
  }
  return ans;
}

// 73,74,75,71,69,72,76,73
// 0  1  2  3  4   5  6  7

//  

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};

  temp = dailyTemperatures(temp);
  for(auto i : temp){
    cout << i << " ";
  }
}