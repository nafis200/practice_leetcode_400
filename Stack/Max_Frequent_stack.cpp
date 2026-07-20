

//  5 7 5 7 4 5

//  1   2   3
//  5   5   5
//  7   7
//  4

#include <bits/stdc++.h>
using namespace std;
class FreqStack {
 public:
  unordered_map<int, stack<int>> group;

  unordered_map<int, int> freq;

  int maxFreq = 0;

  FreqStack() {}

  void push(int val) {
      freq[val]++;
      int f = freq[val];
      maxFreq = max(maxFreq, freq[val]);

      group[f].push(val);
  }

  int pop() {
     int ans = group[maxFreq].top();
     group[maxFreq].pop();
     freq[ans]--;
     if(group[maxFreq].empty()){
        maxFreq--;
     }
     return ans;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}