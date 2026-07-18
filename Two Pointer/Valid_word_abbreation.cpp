
#include <bits/stdc++.h>
using namespace std;

// 18

 bool validWordAbbreviation(string word, string abbr) {
    int n1 = word.size();
    int n2 = abbr.size();
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(word[i] == abbr[j]){
            i++; j++;
        }
        else if(isdigit(abbr[j])){
            int num = 0;
            if(abbr[j] == '0'){
                return false;
            }
            while(j < n2 && isdigit(abbr[j])){
               num = num * 10 + abbr[j] - '0';
               j++;
            }
            i += num;
        }
        else{
            break;
        }
    }
    if(i == n1 && j == n2){
        return true;
    }
    return false;
 }



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string word = "apple", abbr = "a3e";

  cout << validWordAbbreviation(word, abbr);
}



