
#include<bits/stdc++.h>
using namespace std;
int firstUniqChar(string s){
   vector<int>mp(26, 0);
   for(int i = 0; i < s.size(); i++){
        mp[s[i] - 'a']++;
   }
   int ans = -1;
   for(int i = 0; i < s.size(); i++){
      if(mp[s[i] - 'a'] == 1){
         ans = i;
         break;
      }
   }
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "leetcode";
    cout << firstUniqChar(s) << "\n";

}