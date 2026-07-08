

// nafis or nafisa


#include <bits/stdc++.h>
using namespace std;
 vector<int> memo;
    unordered_set<string> wordSet;

    bool solve(int i, string &s) {
        if (i == s.size()) return true;
        if (memo[i] != -1) return memo[i];

        for (int j = i; j < s.size(); j++) {
            if (wordSet.count(s.substr(i, j - i + 1))) {
                if (solve(j + 1, s)) {
                    return memo[i] = 1;
                }
            }
        }

        return memo[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo.assign(s.size(), -1);
        wordSet.insert(wordDict.begin(), wordDict.end());
        return solve(0, s);
    }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  cout << wordBreak(s, wordDict) << "\n";
}