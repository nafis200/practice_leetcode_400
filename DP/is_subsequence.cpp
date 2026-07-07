
#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
  int n = s.size();
  int n1 = t.size();

  int i = 0;
  for(int j = 0; j < n1; j++){
      if(s[i] == t[j]){
         i++;
      }
  }
  if(i == n){
    return true;
  }
  return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "abc", t = "ahbgdc";
    cout << isSubsequence(s, t);
}