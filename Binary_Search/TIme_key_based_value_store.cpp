#include<bits/stdc++.h>
using namespace std;
class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
         if(mp.find(key) == mp.end()){
            return "";
         }
         vector<pair<string,int>>&v = mp[key];

         int l = 0, r = v.size() - 1;
         string ans = "";
         int mid = 0;
         while(l <= r){
            mid = (l + r) / 2;
            if(v[mid].second <= timestamp){
                 ans = v[mid].first;
                 l = mid + 1;
            }
            else{
                r = mid - 1;
            }
         }
         return ans;
    }
};
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}

