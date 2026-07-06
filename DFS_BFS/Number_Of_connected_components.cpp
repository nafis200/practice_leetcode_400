
#include <bits/stdc++.h>
using namespace std;
vector<bool> vis;

void DFS(vector<vector<int>>& g, int node) {
  vis[node] = true;
  for (auto v : g[node]) {
    if (vis[v] == false) {
      DFS(g, v);
    }
  }
}

int countComponents(int n, vector<vector<int>>& edges) {
  vector<vector<int>> g(n);
  vis.assign(n, false);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int components = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == false) {
      DFS(g, i);
      components++;
    }
  }
  return components;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
  int n = 5;

  int ans = countComponents(n, edges);
  cout << ans << "\n";
}