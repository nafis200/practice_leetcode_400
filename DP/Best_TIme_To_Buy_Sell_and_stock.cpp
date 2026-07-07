
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
   int n = prices.size();  
   int ans = 0;
   int mx = 0;
   for(int i = n - 1; i >= 0; i--){
       if(mx < prices[i]){
           mx = prices[i];
       }
       else{
        ans = max(ans, mx - prices[i]);
       }
   } 
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}