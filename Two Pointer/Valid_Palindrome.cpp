
#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s, int j){
  return ((s[j] >= 'a' && s[j] <= 'z') || 
  (s[j] >= 'A' && s[j] <= 'Z') || 
  (s[j] >= '0' && s[j] <= '9')
);
}

int RemoveSpace(string& s) {
  int i = 0;
  int n = s.size();
  int j = 0;
  while (j < n) {
    if (isValid(s, j)) {
      s[i] = tolower(s[j]);
      i++;
    }
    j++;
  }
  return i;
}

bool isPalindrome(string s) {
  int r = RemoveSpace(s);
  int l = 0;
  r--;
  while (l <= r && s[l] == s[r]) {
    l++;
    r--;
  }
  return (l >= r);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "OP";
  cout << isPalindrome(s) << "\n";
}
