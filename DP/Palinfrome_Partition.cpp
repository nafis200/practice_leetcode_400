
#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>ans;
int n;
vector<string>res;

// worst case n * 2^n

bool palindrome(int l, int r, string s){
     while(l <= r && s[l] == s[r]){
          l++;
          r--;
     }
     if(l > r){
        return true;
     }
     return false;
}


void dp(int i, string s){
    if(i == n){
       ans.push_back(res);
       return;
    }
    for(int j = i; j < n; j++){
         if(palindrome(i, j, s)){
            res.push_back(s.substr(i, j - i + 1));
            dp(j + 1, s);
            res.pop_back();
         }
    }
    return;
}

vector<vector<string>> partition(string s) {
   n = s.size();
   dp(0, s);
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "aab";
    vector<vector<string>>ans1 = partition(s);

    for(auto v : ans1){
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }

}

//   aab
// a a b

//  aa b