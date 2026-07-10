
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int k = 2;
    vector<int>buy(k + 1, INT_MIN);
    vector<int>sell(k + 1, 0);
    for(auto p : prices){
        for(int j = 1; j <= k; j++){
            buy[j] = max(buy[j], sell[j - 1] - p);
            sell[j] = max(sell[j], buy[j] + p);
        }
    }
    return sell[k];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k = 2;
  vector<int> prices = {3,2,6,5,0,3};
  cout << maxProfit(prices) << "\n";
}