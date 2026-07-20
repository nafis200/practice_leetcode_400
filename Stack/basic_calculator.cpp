

#include<bits/stdc++.h>
using namespace std;

// (1+(4+5+2)-3)+(6+8)

//  0 1
//  1 1

// result = 11
// sign = -1

//  9


int calculate(string s) {
   stack<int>prevNumber,prevSign;
   int n = s.size();
   int result = 0;
   int sign = 1;
   for(int i = 0; i < n; i++){
     if(s[i] == ' '){
        continue;
     }
     if(isdigit(s[i])){
        int num = 0;
        while(i < n && isdigit(s[i])){
            num = 1LL * num * 10 + s[i] - '0';
            i++;
        }
        i--;
        result = result + 1LL * num * sign;
     }
     else if(s[i] == '+'){
        sign = 1;
     }
     else if(s[i] == '-'){
        sign = -1;
     }
     else if(s[i] == '('){
        prevNumber.push(result);
        prevSign.push(sign);
        sign = 1;
        result = 0;
     }
     else{
         int res = prevNumber.top();
         prevNumber.pop();
         int si = prevSign.top();
         prevSign.pop();

         result = 1LL * res + result * si;
     }
   }
   return result;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s  = "(1+(4+5+2)-3)+(6+8)";

    int ans = calculate(s);
    cout << ans << "\n";
}

// + 1 + 2 + 3

// res = 3

// sign = 1