
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int benefit = 0;
    int mx = prices[n];
    for(int i = 1; i < n; i++){
        if(prices[i] > prices[i - 1]){
            benefit += prices[i] - prices[i - 1];
        }
    }
   return benefit;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>prices = {7,1,5,3,6,4};
  cout << maxProfit(prices) << "\n";
}

