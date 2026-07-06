
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  unordered_map<
    string,
    priority_queue<string, vector<string>, greater<string>>
> g;

    vector<string>ans;

void DFS(string src){
    auto &pq = g[src];
    ans.push_back(src);
    while(!pq.empty()){
        string next = pq.top();
        pq.pop();
        DFS(next);
    }
    
}    

vector<string> findItinerary(vector<vector<string>>& tickets) {
    for(auto x : tickets){
        string u = x[0];
        string v = x[1];
        g[u].push(v);
    }
    DFS("JFK");
    return ans;
}
};