
#include <bits/stdc++.h>
using namespace std;
vector<bool>vis;
void DFS(vector<vector<int>>& rooms, int node){
    vis[node] = true;
    int sz = rooms[node].size();
    for(int i = 0; i < sz; i++){
        if(vis[rooms[node][i]] == false){
            DFS(rooms, rooms[node][i]);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vis.assign(n, false);
    DFS(rooms, 0);
    bool ok = true;
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            ok = false;
        }
    }
    return ok;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> rooms = {
    {1, 3},
    {3, 0, 1},
    {2},
    {0}
};

bool ans = canVisitAllRooms(rooms);
cout << ans << "\n";
}