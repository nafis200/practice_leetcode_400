
#include <bits/stdc++.h>
using namespace std;
bool checkValidString(string s) {
  stack<int> st;
  stack<int> star;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      star.push(i);
    } else if (s[i] == '(') {
      st.push(i);
    } else {
      if (st.empty() && star.empty()) {
        return false;
      } else if (!st.empty()) {
        st.pop();
      } else {
        star.pop();
      }
    }
  }
  if (st.size() > star.size()) {
    return false;
  }
  while(!st.empty()){
     int x = st.top();
     int y = star.top();
     st.pop();
     star.pop();
     if(x > y){
        return false;
     }
  }
  return true;
}

// ****((((*******

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "**((";
  cout << checkValidString(s) << "\n";
}