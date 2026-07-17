
#include <bits/stdc++.h>
using namespace std;

// Let's take LeetCode contest

// i = 0

// string reverseWords(string s) {
//    int n = (int)s.size();
//    int i = 0, j = 0;
//    while(j <= n){
//       if(j == n ||  s[j] == ' '){
//          reverse(s.begin() + i, s.begin() + j);
//          i = j + 1;
//       }
//       j++;
//    }   
  
//    return s;
// }

string reverseWords(string s) {
   stringstream ss(s);
   string temp;
   string ans;
   while(getline(ss, temp, ' ')){
      string s1 = temp;
      reverse(s1.begin(),s1.end());
      ans += s1;
      ans += ' ';
   }
   ans.pop_back();
   return ans;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s = "Let's take LeetCode contest";

  cout << reverseWords(s) << "\n";
}