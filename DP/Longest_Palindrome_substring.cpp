
#include <bits/stdc++.h>
using namespace std;

int n;
string t;

bool isPalindrome(int l, int r) {
  while (l <= r) {
    if (t[l] == t[r]) {
      l++;
      r--;
    } else {
      return false;
    }
  }
  return true;
}

string longestPalindrome(string s) {
  n = s.size();
  t = s;
  vector<int> odd(n), even(n);
  for (int center = 0; center < n; center++) {
    int ans = 0;
    int l = 0;
    int r = min(center, n - center - 1);

    while (l <= r) {
      int mid = (l + r) / 2;
      if (isPalindrome(center - mid, center + mid)) {
        l = mid + 1;
        ans = mid;
      } else {
        r = mid - 1;
      }
    }
    odd[center] = ans;
  }

  //   even center

  for (int center = 0; center < n; center++) {
    int l = 0, r = min(center - 1, n - 1 - center);
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (isPalindrome(center - 1 - mid, center + mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    even[center] = ans;
  }

//   a b a
//   0 1 0

  int mx = 0;
  int ans_l = 0, ans_r = 0;
  for(int i = 0; i < n; i++){
     int len = odd[i] * 2 + 1;
     if(len > mx){
        mx = len;
        ans_l = i - odd[i];
        ans_r = i + odd[i];
     }
  }

//    abba
//   -1 -1 1 -1
  for(int i = 0; i < n; i++){
     int len = 2 * (even[i] + 1);
     if(len > mx){
         mx = len;
         ans_l = i - even[i] - 1;
         ans_r = i + even[i];
     }
  }
  return s.substr(ans_l, ans_r - ans_l + 1);

  //   abba
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "abba";
  cout << longestPalindrome(s) << "\n";
}