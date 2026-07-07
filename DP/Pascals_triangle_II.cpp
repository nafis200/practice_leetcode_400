#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int numRows) {
   vector<int>triangle(numRows + 1, 1);
   for(int i = 2; i <= numRows; i++){
     for(int j = i - 1; j > 0; j--){
        triangle[j] = triangle[j] + triangle[j - 1];
     }
   }
   return triangle;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int numsRows = 1;
    vector<int>triangle = getRow(numsRows);

    for(auto i : triangle){
        cout << i << " ";
    }
}

