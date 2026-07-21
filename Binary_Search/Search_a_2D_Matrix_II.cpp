#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int n = matrix.size();
     int m = matrix[0].size();
     bool ok = false;
     for(int i = 0; i < n; i++){
        int l = 0, r = m - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[i][mid] == target){
                 ok = true;
                 break;
            }
            else if(matrix[i][mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
            
        }
     }
     return ok;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
    {1, 4, 7, 11, 15},
    {2, 5, 8, 12, 19},
    {3, 6, 9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
};
    
}

// 7 4 3 1 10
//        