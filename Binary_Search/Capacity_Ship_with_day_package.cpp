
#include<bits/stdc++.h>
using namespace std;
//  1 2 3 1 1

bool weightCount(vector<int>& weights, int days, int k){
     int n = weights.size();
     int sum = 0;
     int day = 1;
     for(int i = 0; i < n; i++){
          if(weights[i] > k){
            return false;
          }
          sum += weights[i];
          if(sum > k){
             sum = weights[i];
             day++;
          }
     }
     return day <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
   int l = 1, r = 2e9;
   int ans = 0;  
   while(l <= r){
      int mid = l + (r - l) / 2;
      if(weightCount(weights, days, mid)){
          ans = mid;
          r = mid - 1;
      }
      else{
         l = mid + 1;
      }
   }
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>weights = {1,2,3,1,1};

    int days = 4;

    cout << shipWithinDays(weights, days) << "\n";
}

