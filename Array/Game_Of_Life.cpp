#include <bits/stdc++.h>
using namespace std;
int n;
int m;

bool isValid(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m) {
    return true;
  }
  return false;
}

void gameOfLife(vector<vector<int>>& board) {
  n = board.size();
  m = board[0].size();

  vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};
  vector<int> dy = {1, 0, -1, 0, 1, -1, -1, 1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int count1 = 0;
      for (int k = 0; k < 8; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if (isValid(next_i, next_j)) {
          if (board[next_i][next_j] == 1 || board[next_i][next_j] == 2) {
            count1++;
          }
        }
      }
      if (board[i][j] == 1) {
        if (count1 < 2 || count1 > 3) {
          board[i][j] = 2;
        }
      } else {
        if (count1 == 3) {
          board[i][j] = 3;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 2) {
        board[i][j] = 0;
      }
      if (board[i][j] == 3) {
        board[i][j] = 1;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

  gameOfLife(board);
  for (auto v : board) {
    cout << "[";
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "]\n";
  }
}