#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;
vector<vector<bool>> pacific, atlentic;

bool isValid(vector<vector<int>>& grid, int i, int j, int next_i, int next_j) {
    return next_i >= 0 && next_i < n &&
           next_j >= 0 && next_j < m &&
           grid[next_i][next_j] >= grid[i][j];
}

vector<vector<bool>> BFS(vector<vector<bool>>& pacific,
                         queue<pair<int, int>> q,
                         vector<vector<int>>& grid) {

    while (!q.empty()) {
        auto x = q.front();
        q.pop();

        int i = x.first;
        int j = x.second;

        for (int k = 0; k < 4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];

            if (isValid(grid, i, j, next_i, next_j) &&
                !pacific[next_i][next_j]) {

                pacific[next_i][next_j] = true;
                q.push({next_i, next_j});
            }
        }
    }

    return pacific;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    n = heights.size();
    m = heights[0].size();

    pacific.assign(n, vector<bool>(m, false));
    atlentic.assign(n, vector<bool>(m, false));

    queue<pair<int, int>> q;

    // Pacific
    for (int i = 0; i < m; i++) {
        pacific[0][i] = true;
        q.push({0, i});
    }

    for (int i = 0; i < n; i++) {
        if (!pacific[i][0]) {
            pacific[i][0] = true;
            q.push({i, 0});
        }
    }

    pacific = BFS(pacific, q, heights);

    // Clear queue
    q = queue<pair<int, int>>();

    // Atlantic
    for (int i = 0; i < m; i++) {
        atlentic[n - 1][i] = true;
        q.push({n - 1, i});
    }

    for (int i = 0; i < n; i++) {
        if (!atlentic[i][m - 1]) {
            atlentic[i][m - 1] = true;
            q.push({i, m - 1});
        }
    }

    atlentic = BFS(atlentic, q, heights);

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pacific[i][j] && atlentic[i][j]) {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    heights = pacificAtlantic(heights);

    for (auto v : heights) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}