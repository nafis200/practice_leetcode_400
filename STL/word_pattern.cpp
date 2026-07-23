
#include <bits/stdc++.h>
using namespace std;
bool wordPattern(string pattern, string s) {
  unordered_map<char, string> mp;

  vector<string> v;

  stringstream ss(s);
  string temp;

  while (getline(ss, temp, ' ')) {
    if (temp != " ") {
      v.push_back(temp);
    }
  }
  
  bool ok = true;

  if(pattern.size() != v.size()){
     ok = false;
     return ok;
  }

  

  int n = (int)pattern.size();
  for (int i = 0; i < n; i++) {
    if (mp.find(pattern[i]) != mp.end()) {
      if (mp[pattern[i]] != v[i]) {
        ok = false;
      }
    }
    mp[pattern[i]] = v[i];
  }

  unordered_map<string, char> mp1;
  for (int i = 0; i < n; i++) {
    if (mp1.find(v[i]) != mp1.end()) {
      if (mp1[v[i]] != pattern[i]) {
        ok = false;
      }
    }
    mp1[v[i]] = pattern[i];
  }

  return ok;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}