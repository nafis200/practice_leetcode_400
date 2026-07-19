
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
vector<int>candidate;
int tar;
int n;
void brackTrack(int i, vector<int>&v, int sum){
    if(sum == tar){
        ans.push_back(v);
        return;
    }
    if(sum > tar){
      return;
    }
    for(int j = i; j < n; j++){
        if(j > i && candidate[j] == candidate[j - 1]){
            continue;
        }
        if(sum + candidate[j] <= tar){
             v.push_back(candidate[j]);
             brackTrack(j + 1, v, sum + candidate[j]);
             v.pop_back();
        }
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
   sort(candidates.begin(),candidates.end());  
   
   candidate = candidates;
   tar = target;
   n = candidate.size();
   vector<int>v;
   brackTrack(0, v, 0);
   return ans;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>candidates = {10,1,2,7,6,1,5};
  int target = 8;

  vector<vector<int>>ans = combinationSum2(candidates, target);
}
