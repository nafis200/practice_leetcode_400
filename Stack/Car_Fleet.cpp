#include<bits/stdc++.h>
using namespace std;
int carFleet(int target, vector<int>& position, vector<int>& speed) {
     vector<pair<int,int>>v;
     int n = position.size();
     for(int i = 0; i < n; i++){
         int p = position[i];
         int s = speed[i];
         v.push_back({p, s});
     }    
     sort(v.rbegin(),v.rend());

     stack<double>st;
     for(int i = 0; i < n; i++){
         int p = v[i].first;
         int s = v[i].second;

         double t = (double)(target - p)/ s;
         if(st.empty()){
            st.push(t);
         }
         else{
            if(st.top() < t){
                st.push(t);
            }
         }
     }
     return st.size();
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int target = 10;
    vector<int>position = {6, 8};

    vector<int>speed = {3,2};

    int ans = carFleet(target, position, speed);

    cout << ans << "\n";
}