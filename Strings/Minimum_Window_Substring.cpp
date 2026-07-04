
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    unordered_map<char, int>mp;
    unordered_map<char, int>mp1;
    for(auto it : t){
        mp[it]++;
    }
    int required = mp.size();
    int form = 0;
    int mnLen = INT_MAX;
    int start = 0;
    int left = 0;
    for(int right = 0; right < s.size(); right++){
        char c = s[right];
        mp1[c]++;
        if(mp.count(c) && mp1[c] == mp[c]){
            form++;
        }
        while(form == required){
            if(right - left + 1 < mnLen){
                start = left;
                mnLen = right - left + 1;
            }
          char ch = s[left];
          mp1[ch]--;
          if(mp.count(ch) && mp1[ch] < mp[ch]){
            form--;
          }
          left++;
        }
    }
    if(mnLen == INT_MAX){
        return "";
    }
   return s.substr(start, mnLen);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// s = "ADOBECODEBANC", t = "ABC"