


//  3  1  3  2
//  1  2  3  4


#include<bits/stdc++.h>
using namespace std;
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
     vector<pair<int,int>>v;
     priority_queue<int,vector<int>,greater<int>>pq;    
     int n = nums1.size();
     for(int i = 0; i < n; i++){
         v.push_back({nums2[i], nums1[i]});
     }
     sort(v.rbegin(),v.rend());
     long long ans = 0;
     long long sum = 0;
     for(int i = 0; i < n; i++){
         sum += v[i].second;
         pq.push(v[i].second);
         int small =v[i].first;
         if(pq.size() > k){
            sum -= pq.top();
            pq.pop();
         }
         if(pq.size() == k){
             ans = max(ans, 1LL * small * sum);
         }
     }
     return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
