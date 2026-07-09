#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>memo;

int dp(int i, int j, string& s, string& r){
    if(i == n && j == m){
        return 0;
    }
    if(i == n && j != m){
        return 0;
    }
    if(j == m && i != n){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = 0;
    if(s[i] == r[j]){
        ans = dp(i + 1, j + 1, s, r) + 1;
    }
    else{
        ans = max(ans,dp(i + 1, j, s, r));
        ans = max(ans, dp(i, j + 1, s, r));
    }
    return memo[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
    n = text1.size();
    m = text2.size();
    memo.assign(n, vector<int>(m, -1));
    int ans = dp(0, 0, text1, text2);
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string text1 = "abcde", text2 = "ace";
    int ans = longestCommonSubsequence(text1, text2);

    cout << ans << "\n";
}
