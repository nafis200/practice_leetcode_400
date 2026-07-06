#include<bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isValid(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m){
        return true;
    }
    return false;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
   n = mat.size();
   m = mat[0].size();
   vector<vector<int>>dis(n, vector<int>(m, INT_MAX));
   queue<pair<int,int>>q;
   for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
       if(mat[i][j] == 0){
         dis[i][j] = 0;
         q.push({i, j});
       }
       else{
          dis[i][j] = INT_MAX;
       }
    }
   }

   while(!q.empty()){
     auto x = q.front();
     q.pop();
     int i = x.first;
     int j = x.second;
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(next_i, next_j)){
            if(dis[i][j] + 1 < dis[next_i][next_j]){
                dis[next_i][next_j] = dis[i][j] + 1;
                q.push({next_i, next_j});
            }
        }
     }
   }

   return dis;
   
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> mat = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
};
  mat = updateMatrix(mat);
  for(auto v : mat){
    cout << "[";
    for(auto i : v){
        cout << i << " ";
    }
    cout << "]\n";
  }
}