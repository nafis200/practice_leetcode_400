
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
 }
int32_t main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
 rotate(matrix);
 for(auto v : matrix){
    cout << "[";
    for(auto i : v){
        cout << i << " ";
    }
    cout << "]\n";
 }
}

//  1 4 7
//  2 5 8
//  3 6 9


//  1 4 7
//  2 5 6
//  3 8 9

//  7 4 1
//  8 5 2
//  9 6 3