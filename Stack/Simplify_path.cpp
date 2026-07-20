
#include<bits/stdc++.h>
using namespace std;

// /.../a/../b/c/../d/./

//  /home/

string simplifyPath(string path) {
    stringstream ss(path);
    vector<string>st;
    string temp;
    while(getline(ss, temp, '/')){
        if(temp == ""){
            continue;
        }
        if(temp == ".."){
            if(!st.empty())
            st.pop_back();
            continue;
        }
        if(temp == "."){
            continue;
        }
        st.push_back(temp);
    }
    string ansPath = "";
    for(auto i : st){
        ansPath += '/' + i;
    }
    if(ansPath == ""){
        ansPath += '/';
    }
    return ansPath;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string path = "/.../a/../b/c/../d/./";
    cout << simplifyPath(path) << "\n";

}