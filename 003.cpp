#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

vector<vector<int>> parseInput(const string& s) {
    vector<vector<int>> matrix;
    if (s.length() <= 2) {
        return matrix;
    }

    vector<int> currentRow;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            currentRow.push_back(s[i] - '0');
        } else if (s[i] == ']') {
            if (!currentRow.empty()) {
                matrix.push_back(currentRow);
                currentRow.clear();
            }
        }
    }
    return matrix;
}

string formatOutput(const vector<vector<int>>& matrix) {
    string result = "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        result += "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            result += to_string(matrix[i][j]);
            if (j + 1 < matrix[i].size()) result += ",";
        }
        result += "]";
        if (i + 1 < matrix.size()) result += ",";
    }
    result += "]";
    return result;
}

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // 初始化：所有 0 入队
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // 方向数组
        vector<int> dirs = {0, 1, 0, -1, 0};

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k+1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    string input = "[[0,0,0],[0,1,0],[1,1,1]]";
    vector<vector<int>> mat = parseInput(input);

    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(mat);

    cout << formatOutput(result) << endl; 
    // 输出 [[0,0,0],[0,1,0],[1,2,1]]

    return 0;
}