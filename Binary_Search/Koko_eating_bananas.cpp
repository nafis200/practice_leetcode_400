#include <bits/stdc++.h>
using namespace std;

bool isTime(vector<int>& piles, int h, int k){
     int n = piles.size();
     long long time = 0;
     for(int i = 0; i < n; i++){
         time += 1LL * (piles[i] / k);
         if(piles[i] % k){
            time++;
         }
     }
     return time <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
     int l = 1, r = 2e9;
     int ans = 0;
     int mid = 0;
     while(l <= r){
        mid = l + (r - l) / 2;
        if(isTime(piles, h, mid)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
     }    
     return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  cout << minEatingSpeed(piles, h) << "\n";
}