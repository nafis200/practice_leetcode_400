#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:

//  stack 1:   3 2 1

// stack 2 : 1 2 3

    stack<int>st,st1;
    MyQueue() {
        
    }
    
    void push(int x) {
          st.push(x);     
    }
    
    int pop() {
        int x = -1;
        if(empty()){
           return x;
        }
        if(st1.empty()){
            while(!st.empty()){
                st1.push(st.top());
                st.pop();
            }
        }
       x = st1.top();
       st1.pop();
       return x;
    }
    
    int peek() {
        int x = -1;
        if(empty()){
           return x;
        }
        if(st1.empty()){
            while(!st.empty()){
                st1.push(st.top());
                st.pop();
            }
        }
       x = st1.top();
       return x;
    }
    
    bool empty() {
        if(st.empty() && st1.empty()){
            return true;
        }  
        return false;
    }
};
int32_t main(){
    ios_base::sync_with_stdio(0);

}

