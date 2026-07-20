#include<bits/stdc++.h>
using namespace std;
 vector<int> asteroidCollision(vector<int>& asteroids) {
   vector<int>st;
   int n = (int)asteroids.size();
   for(int i = 0; i < n; i++){
      bool destroy = false;
      int x = asteroids[i];
      if(!st.empty() && st.back() > 0 && x < 0){
        while(!st.empty() &&  st.back() > 0 && st.back() < abs(x)){
            st.pop_back();
        }
        if(!st.empty() && st.back() == abs(x)){
            destroy = true;
            st.pop_back();
        }
        else if(!st.empty() && st.back() > abs(x)){
            destroy = true;
        }
      }
      if(!destroy){
        st.push_back(x);
      }
   }
   return st;
  
}

// -2 -2 1 -2
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>v = {-2, -2, 1, -2};

    v = asteroidCollision(v);

    for(auto i : v){
        cout << i << " ";
    }
}