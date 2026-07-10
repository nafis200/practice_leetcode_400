
#include<bits/stdc++.h>
using namespace std;
string s1, t1;
int n, m;
vector<vector<int>>memo;
int dp(int i, int j){
    if(i == n && j == m){
        return 1;
    }
    if(j == m){
        return 1;
    }
    if(i == n){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = 0;
    if(s1[i] == t1[j]){
        ans = dp(i + 1, j + 1) + dp(i + 1, j);
    }
    else{
        ans += dp(i + 1, j);
    }
    return memo[i][j] = ans;
}
int numDistinct(string s, string t) {
    n = s.size();
    m = t.size();
    s1 = s;
    t1 = t;
    memo.assign(n, vector<int>(m, -1));
    int ans = dp(0, 0);
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t) << "\n";
}