
#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
   stack<char>st;
   for(auto i : s){
      if(i == '(' || i == '{' || i == '['){
        st.push(i);
      }
      else{
         if(st.empty()){
            return false;
         }
         else if(i == ')' && st.top() == '('){
            st.pop();
         }
         else if(i == '}' && st.top() == '{'){
            st.pop();
         }
         else if(i == ']' && st.top() == '['){
            st.pop();
         }
         else{
            return false;
         }
      }
   }
   if(st.empty()){
    return true;
   }
   return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "()[]{}";
    cout << isValid(s) << "\n";
}