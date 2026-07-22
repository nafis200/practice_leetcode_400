

//  1  5  9
//  10 11 13
//  12 13 15



#include<bits/stdc++.h>
using namespace std;


bool kthCount(vector<vector<int>>&matrix, int k, int num){
    int count = 0;
    int row = matrix.size() - 1;
    int col = 0;
    int n = matrix.size() - 1;
    while(row >= 0 && col <= n){
        if(matrix[row][col] <= num){
            count += (row + 1);
            col++;
        }
        else{
           row--;
        }
    }
    return count >= k;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size() - 1;
    int l = matrix[0][0], r = matrix[n][n];
    int ans = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(kthCount(matrix, k, mid)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
    {1, 5, 9},
    {10, 11, 13},
    {12, 13, 15}
};
}
