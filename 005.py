def min_cost_path(grid, x, y):
    n = len(grid)
    dp = [[0] * n for _ in range(n)]

    dp[0][0] = grid[0][0]

    # 初始化第一行
    for j in range(1, y + 1):
        dp[0][j] = dp[0][j - 1] + grid[0][j]

    # 初始化第一列
    for i in range(1, x + 1):
        dp[i][0] = dp[i - 1][0] + grid[i][0]

    # 填充 DP
    for i in range(1, x + 1):
        for j in range(1, y + 1):
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

    return dp[x][y]


if __name__ == "__main__":
    n = int(input("请输入矩阵大小 n: "))
    grid = []
    print(f"请输入 {n}x{n} 的矩阵:")
    for _ in range(n):
        row = list(map(int, input().split()))
        grid.append(row)

    x, y = map(int, input("请输入目标坐标 (x y): ").split())

    if x < 0 or y < 0 or x >= n or y >= n:
        print("目标坐标无效!")
    else:
        result = min_cost_path(grid, x, y)
        print(f"从 (0,0) 到 ({x},{y}) 的最小成本路径和为: {result}")