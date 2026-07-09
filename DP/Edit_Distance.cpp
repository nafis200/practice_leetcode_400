
#include<bits/stdc++.h>
using namespace std;

int n;
int m;
vector<vector<int>>memo;
int dp(int i, int j, string& word1, string& word2){
    if(i == n && j == m){
        return 0;
    }
    if(i == n){
        return m - j;
    }
    if(j == m){
        return n - i;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = 1000;
    if(word1[i] == word2[j]){
        ans = dp(i + 1, j + 1, word1, word2);
    }
    else{
        ans = min(ans, dp(i + 1, j + 1, word1, word2) + 1);

        ans = min(ans, dp(i + 1, j, word1, word2) + 1);
        
        ans = min(ans, dp(i, j + 1, word1, word2) + 1);
    }
    return memo[i][j] = ans;
}
int minDistance(string word1, string word2) {
   n = word1.size();
   m = word2.size();
   memo.assign(n, vector<int>(m, -1));
   return dp(0, 0, word1, word2);

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}