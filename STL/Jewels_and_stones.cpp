
#include<bits/stdc++.h>
using namespace std;
int numJewelsInStones(string jewels, string stones) {
     unordered_map<char,int>mp;
     
     for(auto it : jewels){
        mp[it]++;
     }
     int cnt = 0;

     for(auto i : stones){
        if(mp.find(i) != mp.end()){
            cnt += mp[i];
        }
     }
     return cnt;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string jewels = "aA", stones = "aAAbbbb";
    
    cout << numJewelsInStones(jewels, stones) << "\n";
}