
#include<bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
     stack<char>st;
     for(auto i : s){
         if(st.empty()){
            st.push(i);
         }
         else if(st.top() == i){
            st.pop();
         }
         else{
            st.push(i);
         }
     }  

     string ans = "";
     while(!st.empty()){
        ans += st.top();
        st.pop();
     }
     reverse(ans.begin(),ans.end());
     return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}