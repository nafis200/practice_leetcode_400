
#include <bits/stdc++.h>
using namespace std;

class MinStack {
 public:
  stack<int> st, mn;
  MinStack() {}

  void push(int value) {
    st.push(value);
    if (mn.empty()) {
      mn.push(value);
    } else {
      int minimum = min(mn.top(), value);
      mn.push(minimum);
    }
  }

  void pop() {
    if (!st.empty()) {
      st.pop();
      mn.pop();
    }
  }

  int top() {
     if(!st.empty()){
        return st.top();
     }
     return 0;
  }

  int getMin() {
     return mn.top();
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
