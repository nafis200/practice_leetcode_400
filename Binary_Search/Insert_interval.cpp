// [[1,2],[3,5],[6,7],[8,10],[12,16]],

// newInterval = [4,8]

// endTime < startTime;

// Overlapping
// startTime <= endTIme


#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
     int n = intervals.size();
     int i = 0;
     vector<vector<int>>ans;
     while(i < n && intervals[i][1] < newInterval[0]){
         ans.push_back(intervals[i]);
         i++;
     }
     int mn = newInterval[0];
     int mx = newInterval[1];
     while(i < n && intervals[i][0] <= newInterval[1]){
          mn = min(mn, intervals[i][0]);
          mx = max(mx,intervals[i][1]);
          i++;
     }
     
     ans.push_back({mn, mx});

     while(i < n){
         ans.push_back(intervals[i]);
         i++;
     }
    return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};

  vector<int> newInterval = {4, 8};

  vector<vector<int>>ans = insert(intervals, newInterval);
}