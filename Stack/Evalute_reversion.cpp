
#include <bits/stdc++.h>
using namespace std;

// "10","6","9","3","+","-11","*","/","*","17","+","5","+"

//  10 6 12 -11

int evalRPN(vector<string>& tokens) {
    stack<int>st;
    int n = tokens.size();
    for(int i = 0; i < n; i++){
        if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
            int num = stoi(tokens[i]);
            st.push(num);
        }
        else if(tokens[i] == "+"){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x + y);
        }
        else if(tokens[i] == "-"){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y - x);
        }
        else if(tokens[i] == "*"){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x * y);
        }
        else if(tokens[i] == "/"){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y / x);
        }
    }

    int x = 0;
    if(!st.empty()){
        x = st.top();
    }
  
    return x;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string>token = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

  int ans = evalRPN(token);
  cout << ans << "\n";
}