// "i","love","leetcode","i","love","coding"

//  i --> 2
//  love --> 2

#include<bits/stdc++.h>
using namespace std;

class cmp{
   public: 
   bool operator()(pair<string,int>&a, pair<string,int>&b){
         if(a.second == b.second){
            return a.first < b.first;
         }
         return a.second > b.second;
   }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int>mp;
    for(auto i : words){
        mp[i]++;
    }   
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>pq;
    for(auto it : mp){
        pq.push(it);
        if(pq.size() > k){
            pq.pop();
        }
    }
    vector<string>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().first);
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string>words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
}