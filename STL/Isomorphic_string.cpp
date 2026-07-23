
#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
   int n = s.size();
   unordered_map<char,char>word, word1;
   bool ok = true;
   for(int i = 0; i < n; i++){
      if(word.find(s[i]) != word.end()){
        if(word[s[i]] != t[i]){
            ok = false;
        }
      }
      word[s[i]] = t[i];
   }

   for(int i = 0; i < n; i++){
      if(word1.find(t[i]) != word1.end()){
        if(word1[t[i]] != s[i]){
            ok = false;
        }
      }
      word1[t[i]] = s[i];
   }

   return ok;

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "egg", t = "add";

    cout << isIsomorphic(s, t) << "\n";
}