
#include<bits/stdc++.h>
using namespace std;
int minSwaps(string s) {
   int swap = 0;
   int balanced = 0;
   for(auto i : s){
     if(i == ']'){
        balanced--;
        if(balanced < 0){
            swap++;
            balanced = 1;
        }
     }
     else{
        balanced++;
     }
   }    
   return swap;
}

// ]]] [[[
// [] [][]

// [ +1
// ] -1

// swap = 2;
// balanced = -1;
// balanced = 1;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}