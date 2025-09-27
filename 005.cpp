#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostPath(const vector<vector<int>>& grid, int x, int y) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    // 初始化第一行
    for (int j = 1; j <= y; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    // 初始化第一列
    for (int i = 1; i <= x; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // 填充 dp
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[x][y];
}

int main() {
    int n;
    cout << "请输入矩阵大小 n: ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    cout << "请输入 " << n << "x" << n << " 的矩阵:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int x, y;
    cout << "请输入目标坐标 (x y): ";
    cin >> x >> y;

    if (x < 0 || y < 0 || x >= n || y >= n) {
        cout << "目标坐标无效!" << endl;
        return 0;
    }

    int result = minCostPath(grid, x, y);
    cout << "从 (0,0) 到 (" << x << "," << y << ") 的最小成本路径和为: " << result << endl;

    return 0;
}