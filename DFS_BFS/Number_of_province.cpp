
#include<bits/stdc++.h>
using namespace std;
vector<bool>vis;

void DFS(vector<vector<int>>& isConnected, int node){
    vis[node] = true;
    int m = isConnected[0].size();
    for(int i = 0; i < m; i++){
        if(isConnected[node][i] == 1 && vis[i] == false){
            DFS(isConnected, i);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int m = isConnected[0].size();
    vis.assign(n, false);
    int connect = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            DFS(isConnected, i);
            connect++;
        }
    }
    return connect;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 1}
};
 
 int ans = findCircleNum(grid);
 cout << ans << "\n";
}