#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
   vector<vector<int>>pascal;
   for(int i = 0; i < numRows; i++){
       vector<int>triangle;
       for(int j = 0; j <= i; j++){
         if(j == 0 || j == i){
            triangle.push_back(1);
         }
         else{
            int x = pascal[i - 1][j - 1] + pascal[i - 1][j];
            triangle.push_back(x);
         }
       }
       pascal.push_back(triangle);
   }        
   return pascal;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int numsRows = 5;
    vector<vector<int>>ans = generate(numsRows);

    for(auto v : ans){
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
}

