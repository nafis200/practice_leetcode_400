
#include<bits/stdc++.h>
using namespace std;
bool ok;
vector<bool>vis;

void DFS(vector<vector<int>>&g, int node, int parent){
    if(ok){
        return;
    }
    vis[node] = true;
    for(auto v : g[node]){
        if(vis[v] == false){
           DFS(g, v, node);
        }
        else if(v != parent && vis[v] == true){
            ok = true;
            return;
        }
    }
}

bool validTree(int n, vector<vector<int>>& edges) {
   int connected = 0;
   ok = false;
   vis.assign(n + 1, false);
   vector<vector<int>>graph(n + 1);
   for(int i = 0; i < edges.size(); i++){
      int u = edges[i][0];
      int v = edges[i][1];
      graph[u].push_back(v);
      graph[v].push_back(u);
   }
   for(int i = 0; i < n; i++){
    if(vis[i] == false){
        DFS(graph, i, -1);
        connected++;
    }
   }
   if(ok){
    return false;
   }
   if(connected > 1){
      return false;
   }
   return true;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//  [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]

//  0  1  2  3  1  4

//  0 1 2 3
//  4 5 6