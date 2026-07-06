
#include <bits/stdc++.h>
using namespace std;
string foreignDictionary(vector<string>& words) {
    unordered_set<char>st;
    unordered_map<char, vector<char>>g;
    unordered_map<char,int>indeg;
    for(auto s : words){
        for(auto c : s){
            st.insert(c);
            indeg[c] = 0;
        }
    }

    int n = words.size();
    for(int i = 0; i < n - 1; i++){
        string s = words[i];
        string s1 = words[i + 1];
        int n = s.size(), n1 = s1.size();
        if(n > n1 && s.substr(0, n1) == s1){
            return "";
        }
        int mnlen = min(n, n1);
        for(int i = 0; i < mnlen; i++){
            if(s[i] != s1[i]){
               indeg[s1[i]]++;
               g[s[i]].push_back(s1[i]); 
               break;
            }
        }
    }
   
    vector<char>ans;
    
    vector<char>res;

    for(auto it : indeg){
        if(it.second == 0){
            ans.push_back(it.first);
        }
    }
    while(!ans.empty()){
        char c = ans.back();
        ans.pop_back();
        res.push_back(c);
        for(auto v : g[c]){
            indeg[v]--;
            if(indeg[v] == 0){
                ans.push_back(v);
            }
        }
    }
    string s;
    for(auto i : res){
        s += i;
    }
    if(s.size() == st.size()){
        return s;
    }
    return "";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string>words = {"hrn","hrf","er","enn","rfnn"};

  string ans = foreignDictionary(words);
  cout << ans << "\n";
}