
#include<bits/stdc++.h>
using namespace std;
 int maxProfit(vector<int>& prices){
     int buy = INT_MIN;
     int sell = 0;
     int cool = 0;
     for(auto p : prices){
        int prevBuy = buy;
        int prevSell = sell;
        int prevcool = cool;

         buy = max(prevBuy, prevSell - p);
         cool = prevBuy + p;
         sell = max(prevSell, prevcool);
     }
     return max(sell, cool);
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>prices = {1,2,3,0,2};
    cout << maxProfit(prices) << "\n";
}