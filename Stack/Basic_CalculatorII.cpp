
#include<bits/stdc++.h>
using namespace std;

//  3, 4
int calculate(string s) {
   s.push_back('+');
   int n = s.size();
   stack<int>nums;
   char sign = '+';
   int num = 0;
   for(int i = 0; i < n; i++){
      if(isdigit(s[i])){
         num = 1LL * num * 10 + s[i] - '0';
      }
      else if(s[i] != ' '){
         if(sign == '+'){
            nums.push(num);
         }
         else if(sign == '-'){
            nums.push(-num);
         }
         else if(sign == '*'){
            int x = nums.top();
            nums.pop();
            nums.push(1LL * num * x);
         }
         else if(sign == '/'){
            int x = nums.top();
            nums.pop();
            nums.push(x / num);
         }

         sign = s[i];
         num = 0;
      }
   }
   int ans = 0;
   while(!nums.empty()){
        ans += nums.top();
        nums.pop();
   }
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "+ 3 + 2  * 2";
    int ans = calculate(s);
    cout << ans << "\n";
    
}


//  * 2 +

// sign = *

//  3  2