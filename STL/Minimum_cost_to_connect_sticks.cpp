
#include <bits/stdc++.h>
using namespace std;
int minimumCost(vector<int>& sticks) {
  priority_queue<int, vector<int>, greater<int>> pq;

  for (auto i : sticks) {
    pq.push(i);
  }
  int ans = 0;
  while (pq.size() > 1) {
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();

    int sum = x + y;
    ans += sum;

    pq.push(sum);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> sticks = {1, 8, 3, 5};

  cout << minimumCost(sticks) << "\n";
}