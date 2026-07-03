
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t){
   vector<int>mp(30, 0);
   for(int i = 0; i < s.size(); i++){
      mp[s[i] - 'a']++;
   }
   for(int i = 0; i < t.size(); i++){
      mp[t[i] - 'a']--;
   }
   int ans = 1;
   for(int i = 0; i < 30; i++){
       if(mp[i] > 0 || mp[i] < 0){
         ans = 0;
       }
   }
   return ans;
} 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}