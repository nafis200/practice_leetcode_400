
#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
  string convert(string s, int numRows) {
    string ans = "";
    if(numRows == 1){
        return s;
    }
    int cyclelen = 2 * numRows - 2;
    for(int i = 0; i < numRows; i++){
       for(int j = i; j < s.size(); j += cyclelen){
          ans += s[j];
          if(i != 0 && i != numRows - 1 && j + cyclelen - 2 * i < s.size()){
               ans += s[j + cyclelen - 2 * i];
          }
       }
    }
    return ans;
}
};
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// Row 0: P       I       N
// Row 1: A    L  S    I  G
// Row 2: Y  A    H  R
// Row 3: P       I

// Row 0: 0       6          12
// Row 1: 1    5  7      11  13
// Row 2: 2  4    8  10
// Row 3: 3       9 

//  0   6    12
//  1   7    13
// diagonal 5   11
// 7 - 2    13 - 2

// vertical = numsrows
//  diagonal = nowRows - 2;

// vertical + diagonal = 2*numsrows - 2;