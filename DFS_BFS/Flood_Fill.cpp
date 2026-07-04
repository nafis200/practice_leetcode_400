
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
int Maincol;
bool isValid(vector<vector<int>>&image, int i, int j){
     if(i >= 0 && i < n && j >= 0 && j < m){
         if(image[i][j] == Maincol){
            return true;
         }
         return false;
     }
     return false;
}

void DFS(vector<vector<int>>&image, int i, int j){
    image[i][j] = -1;
    for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(image, next_i, next_j)){
            DFS(image, next_i, next_j);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
      n = image.size();
      m = image[0].size();
      Maincol = image[sr][sc];
      DFS(image, sr, sc);
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(image[i][j] == -1){
                image[i][j] = color;
            }
        }
      }
      return image;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int sr = 1, sc = 1, color = 0;

  vector<vector<int>>ans = floodFill(image, sr, sc, color);
  for(auto v : ans){
     cout << "[";
     for(auto i : v){
        cout << i << " ";
     }
     cout << "]\n";
  }
}