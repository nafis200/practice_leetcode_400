#include<bits/stdc++.h>
using namespace std;




bool hasValue(vector<int> ranges, int val) {
  for (int i = 0; i < ranges.size(); i++) {
    if (ranges[i] == val) {
      return true;
    }
  }
  return false;
}

// 0 1 3

// time o(Range * n)

vector<vector<int>> missingRanges(vector<int>& ranges, int lower, int upper) {
  vector<vector<int>> ans;

  int x = -1;
  for (int i = lower; i <= upper; i++) {
    if (!hasValue(ranges, i)) {
      if (x == -1) {
        x = i;
      }
    } else {
      if (x != -1) {
        ans.push_back({x, i - 1});
        x = -1;
      }
    }
  }

  if (x != -1) {
    ans.push_back({x, upper});
  }

  return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {0, 1, 3, 50, 75};
    int lower = -10, upper = 99;
    
    vector<vector<int>>ans = missingRanges(nums, lower, upper);
    for(auto v : ans){
        cout << "[";
        for(auto i : v){
            cout << i << " ";
        }
        cout << "]\n";
    }
}