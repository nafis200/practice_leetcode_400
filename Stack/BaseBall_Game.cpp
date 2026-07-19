
#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& operations) {
   stack<int>st;
   int n = operations.size();
   for(int i = 0; i < n; i++){
      if(operations[i] == "+"){
         int x = st.top();
         st.pop();
         int y = st.top();
         st.pop();
         
         int sum = x + y;
         st.push(y);
         st.push(x);
         st.push(sum);
    }
    else if(operations[i] == "D"){
        st.push(st.top() * 2);
    }
    else if(operations[i] == "C"){
        st.pop();
    }
    else{
        string s = operations[i];
        int num = 0;
        int sign = 1;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-'){
                sign = -1;
                continue;
            }
            num = num * 10 + s[i] - '0';
        }
        st.push(sign * num);
    }
   }
   int ans = 0;
   while(!st.empty()){
      ans += st.top();
      st.pop();

   }
   return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> operations ={"5","-2","4","C","D","9","+","+"};  

  cout << calPoints(operations) << "\n";
  
}

