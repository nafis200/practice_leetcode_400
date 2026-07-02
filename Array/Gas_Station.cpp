
#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int n = gas.size();
  int mn = INT_MAX;
  int idx = -1;
  int total_gas = 0;
  for(int i = 0; i < n; i++){
     total_gas += (gas[i] - cost[i]);
  }
  if(total_gas < 0){
    return -1;
  }

  int start_point = 0;
  total_gas = 0;
  for(int i = 0; i < n; i++){
     total_gas += (gas[i] - cost[i]);
     if(total_gas < 0){
         start_point = i + 1;
         total_gas = 0;
     }
  }
  return start_point;
}

//  2 3 4
//  3 4 3

//  1 2 3 4 5
//  3 4 5 1 2
//  -2 -2 -2 3 3

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> gas = {2, 3, 4};
  vector<int> cost = {3, 4, 3};
  cout << canCompleteCircuit(gas, cost) << "\n";
}

//  2 3 4
//  3 4 3

//  2 + 3 = 5
//  2 3 4
//  2 0 1
// 3