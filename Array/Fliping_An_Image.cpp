
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
   
    for(auto &v : image){
        int n = v.size();
        int l = 0, r = n - 1;
        while(l <= r){
            if(v[l] == v[r]){
                if(v[r] == 0){
                    v[l] = v[r] = 1;
                }
                else{
                    v[l] = v[r] = 0;
                }
            }
            l++;
            r--;
        }
    }
    return image; 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {
    {1, 1, 0},
    {1, 0, 1},
    {0, 0, 0}
};

grid = flipAndInvertImage(grid);

for(auto v : grid){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n";
}
}