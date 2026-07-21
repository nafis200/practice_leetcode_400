
#include<bits/stdc++.h>
using namespace std;
bool isBadVersion(int n){
    return n >= 4;
}

int firstBadVersion(int n) {
   int l = 0, r = n;
   int ans = -1;
   while(l <= r){
      int mid = l + (r - l) / 2;
      if(isBadVersion(mid)){
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
}