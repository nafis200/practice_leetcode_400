
#include<bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size() - 1;
    stack<int>st;
    st.push(prices[n]);
    for(int i = n - 1; i >= 0; i--){
         while(!st.empty() && st.top() > prices[i]){
            st.pop();
         }
         int x = 0;
         if(!st.empty()){
            x = st.top();
         }
         st.push(prices[i]);
         prices[i] = prices[i] - x;
    }
    return prices;
}

//  6 3

//  1 2 4

//  8 4 6 2 3 1

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>prices = {8,4,6,2,3};

    prices = finalPrices(prices);

    for(auto i : prices){
        cout << i << " ";
    }
}


