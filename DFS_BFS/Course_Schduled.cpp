
#include<bits/stdc++.h>
using namespace std;
//  u, v
//  v --> u
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
    vector<int>indeg(numCourses, 0);
    vector<vector<int>>g(numCourses);
    for(int i = 0; i < n; i++){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        g[v].push_back(u);
        indeg[u]++;
    }
    vector<int>ans;
    for(int i = 0; i < numCourses; i++){
        if(indeg[i] == 0){
            ans.push_back(i);
        }
    }
    vector<int>course;
    while(!ans.empty()){
        int x = ans.back();
        ans.pop_back();
        course.push_back(x);
        for(auto v : g[x]){
            indeg[v]--;
            if(indeg[v] == 0){
                ans.push_back(v);
            }
        }
    }
    if(course.size() == numCourses){
        return course;
    }
    return {};
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}