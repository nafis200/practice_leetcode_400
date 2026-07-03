
#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num) {
  vector<pair<string,int>> mp = {
    {"M",1000},
    {"CM",900},
    {"D",500},
    {"CD",400},
    {"C",100},
    {"XC",90},
    {"L",50},
    {"XL",40},
    {"X",10},
    {"IX",9},
    {"IV", 4},
    {"V",5},
    {"I",1}
};
  int i = 0;
  string ans = "";
  while(num > 0){
     while(num >= mp[i].second){
         ans += mp[i].first;
         num -= mp[i].second;
     }
     i++;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}