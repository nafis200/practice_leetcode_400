
#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
   
    int n = matrix.size();
    int m = matrix[0].size();

    int l = 0, r = n * m - 1;
    bool ans = false;
    int mid = 0;
    while(l <= r){
        mid = (l + r) / 2;
        int row = mid / m;
        int col = mid % m;
        if(matrix[row][col] == target){
            ans = true;
            break;
        }
        else if(matrix[row][col] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }

    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 60}
};

cout << searchMatrix(matrix, 3) << "\n";
}