
#include<bits/stdc++.h>
using namespace std;
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>mp;

    int n = strs.size();
    for(int i = 0; i < n; i++){
        string s = strs[i];
        sort(s.begin(),s.end());
        mp[s].push_back(strs[i]);
    }

    vector<vector<string>>ans;
    for(auto v : mp){
        vector<string>take;
        for(auto i : v.second){
            take.push_back(i);
        }
        ans.push_back(take);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string>strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>>ans = groupAnagrams(strs);
    for(auto v : ans){
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
}