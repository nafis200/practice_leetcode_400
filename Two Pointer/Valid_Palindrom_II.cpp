
#include <bits/stdc++.h>
using namespace std;

// bool isPalindrom(string s, int x) {
//   int l = 0, r = s.size() - 1;
//   if (l == x) {
//     l++;
//   }
//   if (r == x) {
//     r--;
//   }
//   while (l <= r && s[l] == s[r]) {
//     l++;
//     r--;
//     if (l == x) {
//       l++;
//     }
//     if (r == x) {
//       r--;
//     }
//   }
//   if(l > r){
//     return true;
//   }
//   return false;
// }

// bool validPalindrome(string s) {
//     bool ok = false;
//     int n = s.size();
//     for(int i = -1; i <= n; i++){
//         ok |= isPalindrom(s, i);
//     }
//     return ok;
// }

bool isPalindrom(string s, int l, int r) {
    while(l <= r && s[l] == s[r]){
        l++;
        r--;
    }
    if(l >= r){
        return true;
    }
    return false;
}

bool validPalindrome(string s) {
    bool ok = false;
    int n = s.size();
    int l = 0, r = s.size() - 1;
    int cnt = 0;
    while(l <= r){
       if(s[l] == s[r]){
         l++;
         r--;
       }
       else{
          if(isPalindrom(s, l + 1, r)){
            ok = true;
            break;
          }
          else if(isPalindrom(s, l, r - 1)){
            ok = true;
            break;
          }
          else{
            break;
          }
       }
       
    }
    if(l >= r){
        ok = true;
    }
    return ok;
}

// abxa

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "abca";
  cout << validPalindrome(s) << "\n";
}

//  abxa
