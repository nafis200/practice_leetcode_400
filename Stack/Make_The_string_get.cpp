
#include<bits/stdc++.h>
using namespace std;
string makeGood(string s) {
   stack<int>st;
   for(int i = 0; i < s.size(); i++){
      if(st.empty()){
          st.push(s[i] - '0');
      }
      else{
         int x = s[i] - '0';
         if(abs(st.top() - x) == 32){
            st.pop();
         }
         else{
            st.push(x);
         }
      }
   }
   string ans = "";
   while(!st.empty()){
      ans += st.top() + '0';
      st.pop();
   }
   reverse(ans.begin(),ans.end());
   return ans;
}
int32_t main(){
    string s = "leEeetcode";
    cout << makeGood(s) << "\n";
}