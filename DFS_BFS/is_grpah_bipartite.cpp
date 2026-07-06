
#include<bits/stdc++.h>
using namespace std;

bool ok;
vector<bool>vis;
vector<int>col;

void DFS(int node,vector<vector<int>>& graph, int color){
     vis[node] = true;
     col[node] = color;
     for(auto v : graph[node]){
        if(!vis[v]){
            DFS(v, graph, color ^ 1);
        }
        else if(col[v] == col[node]){
            ok = false;
        }
     }
}

bool isBipartite(vector<vector<int>>& graph) {
   int n = graph.size();
   set<int>st;
   for(auto v : graph){
     for(auto u : v){
         st.insert(u);
     }
   }
  vis.assign(n, false);
  col.assign(n, 0);
  ok = true;
  for(int i = 0; i < n; i++){
    if(!vis[i]){
        DFS(i, graph, 0);
    }
}
  return ok;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> graph = {
    {1, 3},
    {0, 2},
    {1, 3},
    {0, 2}
};
bool ans = isBipartite(graph);
cout << ans << "\n";
}