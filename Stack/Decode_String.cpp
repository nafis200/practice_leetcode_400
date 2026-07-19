
#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
   stack<string>st;
   stack<int>nums;
   string cur = "";
   int num = 0;
   for(int i = 0; i < s.size(); i++){
      if(isdigit(s[i])){
         num = num * 10 + s[i] - '0';
      }
      else if(s[i] == '['){
         st.push(cur);
         nums.push(num);
         num = 0;
         cur = "";
      }
      else if(s[i] == ']'){
         string prev = st.top();
         st.pop();
         int number = nums.top();
         nums.pop();
         string part = cur;
         for(int k = 1; k < number; k++){
            cur += part;
         }

         cur = prev + cur;

      }
      else{
         cur += s[i];
      }
   }   
   return cur;
}


// string: ""
// int:  3

// prev = "a"
// num = 
// cur = acc

// 3[a2[c]]


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "3[a]2[bc]";
  cout << decodeString(s) << "\n";
}

// string : "" 
// number :  3 
//  3  
//  "" + accaccacc  

// acc

// a
// 2


// 3[a2[c]]

//  3 a

//  ans 2 acc

// accacc