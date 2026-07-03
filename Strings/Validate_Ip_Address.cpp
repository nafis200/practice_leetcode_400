
#include <bits/stdc++.h>
using namespace std;
// 192..12.255

bool IpV4(string ip) {
  vector<string> parts;
  stringstream ss(ip);
  string word;
  while (getline(ss, word, '.')) {
    parts.push_back(word);
  }

  if (parts.size() != 4) {
    return false;
  }

  for (auto part : parts) {
    if (part.empty()) {
      return false;
    }
    if (part.size() > 1 && part[0] == '0') {
      return false;
    }
    if (part.size() > 3) {
      return false;
    }
    int num = 0;
    for (auto i : part) {
      if (!isdigit(i)) {
        return false;
      }
      int x = i - '0';
      num = num * 10 + x;
    }
    if (num < 0 || num > 255) {
      return false;
    }
  }

  return true;
}

bool Ipv6(string ip) {
  vector<string> parts;
  stringstream ss(ip);
  string word;
  while (getline(ss, word, ':')) {
    parts.push_back(word);
  }
  if (parts.size() != 8) {
    return false;
  }
  for (auto part : parts) {
    if (part.empty()) {
      return false;
    }
    if (part.size() > 4) {
      return false;
    }
    for(char c : part){
    if(!(isdigit(c) ||
         (c >= 'a' && c <= 'f') ||
         (c >= 'A' && c <= 'F')))
    {
        return false;
    }
}
  }
  return true;
}

string validIPAddress(string queryIP) {
  string ans = "Neither";
  if (count(queryIP.begin(), queryIP.end(), '.') == 3) {
    if (IpV4(queryIP)) {
      ans = "IPv4";
    }
  }
  if (count(queryIP.begin(), queryIP.end(), ':') == 7) {
    if (Ipv6(queryIP)) {
      ans = "IPv6";
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << validIPAddress("20EE:FGb8:85a3:0:0:8A2E:0370:7334") << "\n";
}