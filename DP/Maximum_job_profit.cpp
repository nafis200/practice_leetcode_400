#include <bits/stdc++.h>
using namespace std;

class cmp {
 public:
  bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    if (a.first.second == b.first.second) {
      return a.first.first < b.first.first;
    }
    return a.first.second < b.first.second;
  }
};

int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                  vector<int>& profit) {
  vector<pair<pair<int, int>, int>> v;
  for (int i = 0; i < (int)startTime.size(); i++) {
    int start = startTime[i];
    int end = endTime[i];
    int pro = profit[i];
    v.push_back({{start, end}, pro});
  }
  sort(v.begin(), v.end(), cmp());
  int n = startTime.size();
  vector<int> dp(n + 1, 0);
  vector<int> pref(n + 1, 0);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int max_profit = v[i].second;
    int j = -1;
    int l = 0, r = i - 1;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (v[i].first.first >= v[mid].first.second) {
        l = mid + 1;
        j = mid;
      } else {
        r = mid - 1;
      }
    }
    if (j != -1) {
      max_profit += pref[j];
    }
    dp[i] = max(dp[i], max_profit);
    if (i != 0) {
      pref[i] = max(dp[i], pref[i - 1]);
    }
    else{
        pref[i] = dp[i];
    }
    mx = max(mx, dp[i]);
  }
  return mx;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> startTime = {1, 2, 3, 3};
  vector<int> endTime = {3, 4, 5, 6};
  vector<int> profit = {50, 10, 40, 70};
  cout << jobScheduling(startTime, endTime, profit) << "\n";
}