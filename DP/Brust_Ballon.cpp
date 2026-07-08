
#include<bits/stdc++.h>
using namespace std;
vector<int>a;
vector<vector<int>>memo;
int mx;
int dp(int l, int r){
    if(r == l + 1){
        return 0;
    }
    if(memo[l][r] != -1){
        return memo[l][r];
    }
    int ans = 0;
    for(int k = l + 1; k < r; k++){
        int left = dp(l, k);
        int right = dp(k, r);
        int gain = a[l] * a[k] * a[r];
        ans = max(ans, left + gain + right);
    }
    return memo[l][r] = ans;
}

int maxCoins(vector<int>& nums){
    a.push_back(1);
    for(auto i : nums){
         a.push_back(i);
    }
    a.push_back(1);
    int n = a.size();
    memo.assign(n, vector<int>(n, -1));
    mx = 0;
    int ans = dp(0, n - 1);
    return ans;
}
int32_t main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int>nums = {3,1,5,8};
   int ans = maxCoins(nums);
   cout << ans << "\n";
}





