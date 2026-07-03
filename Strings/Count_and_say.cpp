#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
     string ans = "1";
     for(int i = 2; i <= n; i++){
         string ans1 = "";
         int j = 0;
         while(j < ans.size()){
            char c = ans[j];
            int count = 0;
            while(c == ans[j]){
                count++;
                j++;
            }
            ans1 += to_string(count);
            ans1 += c;
         }
         ans = ans1;
     }
     return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << countAndSay(4) << "\n";
}

//  1
// 11
// 21
// 1211