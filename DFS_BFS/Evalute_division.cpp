
//  a , b = 2 . 0, 3.0

//  a / b = 2
//  b / c = 3
//  a --> c = 2 * 3

// a -->b = 2
// b -->a = 0.5
// b -->c = 3
// c -->b = 0.333

#include <bits/stdc++.h>
using namespace std;
unordered_set<string> st;
unordered_map<string, vector<pair<string, double>>> g;

double DFS(string src, string dist, double product) {
  if (src == dist) {
    return product;
  }
  st.insert(src);
  for (auto v : g[src]) {
    if (st.find(v.first) == st.end()) {
      double result = DFS(v.first, dist, product * v.second);
      if (result != -1) {
        return result;
      }
    }
  }
  return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations,
                            vector<double>& values,
                            vector<vector<string>>& queries) {
  int n = equations.size();
  for (int i = 0; i < n; i++) {
    string a = equations[i][0];
    string b = equations[i][1];
    double c = values[i];
    g[a].push_back({b, c});
    g[b].push_back({a, 1.0 / c});
  }
  vector<double> ans;
  for (int i = 0; i < queries.size(); i++) {
    string a = queries[i][0];
    string b = queries[i][1];
    if (g.find(a) == g.end() || g.find(b) == g.end()) {
      ans.push_back(-1.0);
      continue;
    }
    ans.push_back(DFS(a, b, 1.0));
    st.clear();
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};

  vector<double> values = {2.0, 3.0};

  vector<vector<string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  vector<double> ans = calcEquation(equations, values, queries);
  for (auto i : ans) {
    cout << i << " ";
  }
}