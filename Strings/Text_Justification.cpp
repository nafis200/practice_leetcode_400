#include <bits/stdc++.h>
using namespace std;

// this is an  8

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> ans;
  int n = words.size();
  for (int i = 0; i < n;) {
    int lineWidth = words[i].size();
    int j = i + 1;
    string s = "";
    while (j < n && lineWidth + 1 + words[j].size() <= maxWidth) {
      lineWidth = lineWidth + 1 + words[j].size();
      j++;
    }
    int wordCount = j - i;
    int space = maxWidth - (lineWidth - (wordCount - 1));
    if (wordCount == 1 || j == n) {
      for (int k = i; k < j; k++) {
        s += words[k];
        if (space > 0) {
          s += " ";
          space--;
        }
      }
      while (space > 0) {
        s += " ";
        space--;
      }
    }
    else{
        int gap = wordCount - 1;
        int DistributedSpace = space / gap;
        int extraSpace = space % gap;
        for(int k = i; k < j; k++){
            s += words[k];
            int ApplySpace = DistributedSpace;
            if(extraSpace){
               ApplySpace++;
               extraSpace--;
            }
            while(k != j - 1 && ApplySpace){
                s += " ";
                ApplySpace--;
            }
        }
    }
    ans.push_back(s);
    i = j;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string>ans = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;

  ans = fullJustify(ans, maxWidth);
  for(auto i : ans){
     cout << i.size() << " ";
     cout << i << "\n";
  }
}

// wordCount 1  j = n

// This is an ____

// j - i
//  8 space 8

// wordCount = 1