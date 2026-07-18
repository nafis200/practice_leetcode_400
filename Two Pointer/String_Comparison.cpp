
#include <bits/stdc++.h>
using namespace std;

//  a 2 b 4 c 3 c c c

// j = 9
// i = 6
// aa bbbb ccc
// a2 b4c3

//  bbbbb#
int compress(vector<char>& chars) {
  int i = 0, j = 0, k = 0;
  for (j; j <= chars.size(); j++) {
    if (j != chars.size() && chars[j] == chars[i]) {
      continue;
    } else {
      char c = chars[j - 1];
      chars[k] = c;
      k++;
      int len = j - i;
      if (len != 1) {
        string s = to_string(len);
        for (int l = 0; l < s.size(); l++) {
          chars[k] = s[l];
          k++;
        }
      }

      i = j;
    }
  }
  return k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b',
                        'b', 'b', 'b', 'b', 'b', 'b','#','#'};

  cout << compress(chars) << "\n";

  for (int i = 0; i < chars.size(); i++) {
    cout << chars[i] << " ";
  }
  //  a a a a a a a a a a a a a a
}
