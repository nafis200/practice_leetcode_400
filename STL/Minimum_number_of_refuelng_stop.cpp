

#include <bits/stdc++.h>
using namespace std;

//  90        fuel = 10

class cmp {
 public:
  bool operator()(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
  }
};

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
  int fuel = startFuel;
  int n = stations.size();
  int stops = 0;
  int i = 0;
  priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
  while(fuel < target){
     while(i < n && fuel >= stations[i][0]){
         pq.push(stations[i]);
         i++;
     }
     if(pq.empty()){
         break;
     }
     vector<int>newFuel = pq.top();
     pq.pop();
     fuel += newFuel[1];
     stops++;
  }
  if(fuel < target){
     stops = -1;
  }
  return stops;
}
// 60
//  30
//  20 30
//  30 30
//  60 40

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int target = 100, startFuel = 10;
  vector<vector<int>> v = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};

  cout << minRefuelStops(target, startFuel, v);
}