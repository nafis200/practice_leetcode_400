#include <bits/stdc++.h>
using namespace std;

vector<char> gene = {'A', 'C', 'G', 'T'};

int minMutation(string startGene, string endGene, vector<string>& bank) {
  unordered_map<string, int> dis;
  unordered_set<string> st;
  for (auto i : bank) {
    dis[i] = INT_MAX;
    st.insert(i);
  }
  queue<string> q;
  q.push(startGene);
  dis[startGene] = 0;
  dis[endGene] = INT_MAX;
//   N + 1 * L
  while (!q.empty()) {
    string x = q.front();
    q.pop();
    int sz = x.size();
    for (int i = 0; i < sz; i++) {
      string s = x;
      for (auto g : gene) {
        s[i] = g;
        if (st.find(s) != st.end()) {
          if (dis[x] + 1 < dis[s]) {
            dis[s] = dis[x] + 1;
            q.push(s);
          }
        }
      }
    }
  }
  if (dis[endGene] == INT_MAX) {
    return -1;
  }
  return dis[endGene];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string startGene = "AACCGGTT", endGene = "AAACGGTA";
  vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

  int ans = minMutation(startGene, endGene, bank);

  cout << ans << "\n";
}