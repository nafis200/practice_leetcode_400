
#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s) {
   reverse(s.begin(),s.end());
   int i = 0;
   stringstream ss(s);
   string temp;
   while(ss >> temp){
      if(!temp.empty()){
         return temp.size();
      }
   }
   return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}