
#include <bits/stdc++.h>
using namespace std;

// //  ba#c##

string makeString(string s) {
  int r = s.size() - 1;
  int cnt = 0;
  while (r >= 0) {
    if (r >= 0 && s[r] == '#') {
      cnt++;
      r--;
    } else {
      if (cnt > 0) {
        while (r >= 0 && cnt > 0) {
          if (s[r] == '#') {
            cnt++;
            r--;
          } else {
            s[r] = '#';
            r--;
            cnt--;
          }
        }
      } else {
        r--;
      }
    }
  }
  return s;
}

// abb##c
// ac

bool backspaceCompare(string s, string t) {
  s = makeString(s);
  t = makeString(t);

  cout << s << "\n";
  cout << t << "\n";

  int n = s.size();
  int n1 = t.size();
  int i = 0, j = 0;
  while (i < n && j < n1) {
    if (s[i] == t[j]) {
      i++;
      j++;
      continue;
    }
    if (s[i] == '#') {
      i++;
    } else if (t[j] == '#') {
      j++;
    } else {
      break;
    }
  }
// isfco##
// isfco####
  while(i < n && s[i] == '#'){
    i++;
  }
  while(j < n1 && t[j] == '#'){
    j++;
  }
  if (i == n && j == n1) {
    return true;
  }
  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "ba#c##";
  cout << backspaceCompare("isfcow#","isfcog#w#") << "\n";
}

// ab##

// 2

// 0 1 0 3 12

//  1 3 0 0 12
