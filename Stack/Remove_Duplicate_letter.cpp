
#include<bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s) {
    unordered_map<char,int>mp;
    unordered_map<char, bool>vis;
    for(auto i : s){
         mp[i]++;
    }
    stack<char>st;
    int n = s.size();
    for(int i = 0; i < n; i++){
        char x = s[i];
        if(vis[x]){
            mp[x]--;
            continue;
        }
        while(!st.empty() && st.top() > x && mp[st.top()] > 0){
             vis[st.top()] = false;
             st.pop();
        }
        st.push(x);
        vis[x] = true;
        mp[x]--;
    }

    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}    

// cccbcaa

// c  b   a
// 0  0   2

//  bc  a

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "cbacdcbc";
    cout << removeDuplicateLetters(s) << "\n";
}

//  c   b   a  d
//  4   2   1  1

//  c 