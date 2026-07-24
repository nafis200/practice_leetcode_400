
#include <bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
  priority_queue<int> pq;
  for (auto i : stones) {
    pq.push(i);
  }
  while(pq.size() > 1){
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();
      int sum = abs(x - y);
      if(sum != 0){
         pq.push(sum);
      }
  }
  if(pq.empty()){
    return 0;
  }
  return pq.top();
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> stones = {2, 2};

  cout << lastStoneWeight(stones) << "\n";
}


//  1 2 3 4 5 6 7 8