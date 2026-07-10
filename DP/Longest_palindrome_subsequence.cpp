
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>memo;
string t;
int dp(int l, int r){
    if(l == r){
        return 1;
    }
    if(l > r){
        return 0;
    }
    if(memo[l][r] != -1){
        return memo[l][r];
    }
    int ans = 0;
    if(t[l] == t[r]){
        ans = max(ans, 2 + dp(l + 1, r - 1));
    }
    else{
        ans = max(ans, dp(l + 1, r));
        ans = max(ans, dp(l, r - 1));
    }
    return memo[l][r] = ans;
}
int longestPalindromeSubseq(string s) {
    t = s;
    int n = s.size();
    memo.assign(n, vector<int>(n , -1));
    return dp(0, n - 1);
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << "\n";
}