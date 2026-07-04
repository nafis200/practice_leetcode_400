
#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, int>dis;
    unordered_set<string>st;
    for(auto i : wordList){
        st.insert(i);
        dis[i] = INT_MAX;
    }
    dis[beginWord] = 1;
    queue<string>q;
    q.push(beginWord);
    while(!q.empty()){
        string x = q.front();
        q.pop();
        int sz = x.size();
        for(int i = 0; i < sz; i++){
            string s = x;
            for(char c = 'a'; c <= 'z'; c++){
                s[i] = c;
                if(st.find(s) != st.end()){
                    if(dis[x] + 1 < dis[s]){
                        dis[s] = dis[x] + 1;
                        q.push(s);
                        st.erase(s);
                    }
                }
            }
        }
    }
    if(dis[endWord] == INT_MAX){
        return 0;
    }
    return dis[endWord];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string beginWord = "hit", endWord = "cog";
  vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
  int ans = ladderLength(beginWord, endWord, wordList);
  cout << ans << "\n";
}