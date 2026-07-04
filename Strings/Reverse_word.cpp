#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
  int i = 0;
  int j = 0;
  int n = s.size();
  while(j < n){
     while(s[j] == ' '){
         j++;
     }
     while(j < n && s[j] != ' '){
        s[i] = s[j];
        i++;
        j++;
     }
     while(j < n && s[j] == ' '){
         j++;
     }
     if(j < n){
         s[i] = ' ';
         i++;
     }
  }
  s.resize(i);
  reverse(s.begin(),s.end());
  n = s.size();
   j = 0;
  int l = 0;
  while(j < n){
     l = j;
     while(j < n && s[j] != ' '){
        j++;
     }
     reverse(s.begin() + l, s.begin() + j);
     j++;
  }
  return s;
}

// hello world



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "  hello world  ";
    string ans = reverseWords(s);
    cout << ans << "\n";
}