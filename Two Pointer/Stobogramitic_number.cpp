#include <bits/stdc++.h>
using namespace std;



bool stobgramic(string s){
    int n = s.size();
    int l = 0, r= n - 1;
    while(l < r){
        char a = s[l];
        char b = s[r];
        if((a == '1' && b == '1') || (a == '8' && b == '8') || (a == '6' && b == '9') || (a == '9' && b == '6') || (a == '0' && b == '0')){
            l++;
            r--;
        }
        else{
            break;
        }
    }
    if(l >= r){
        return true;
    }
    return false;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}