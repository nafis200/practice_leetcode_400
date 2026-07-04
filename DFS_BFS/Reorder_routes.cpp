
#include <bits/stdc++.h>
using namespace std;
vector<bool> vis;

int change = 0;

void DFS(int node, vector<vector<pair<int, int>>> &g) {
    vis[node] = true;
    for(auto v : g[node]){
        if(vis[v.first] == false){
            change += v.second;
            DFS(v.first, g);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections) {
  vis.assign(n, false);
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < connections.size(); i++) {
    int u = connections[i][0];
    int v = connections[i][1];
    g[u].push_back({v, 1});
    g[v].push_back({u, 0});
  }
  DFS(0, g);
  return change;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  int ans = minReorder(6, connections);
  cout << ans << "\n";
}