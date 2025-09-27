from collections import deque

class Solution:
    def updateMatrix(self, mat):
        if not mat or not mat[0]:
            return []
        
        m, n = len(mat), len(mat[0])
        dist = [[float('inf')] * n for _ in range(m)]
        q = deque()

        # 初始化：所有 0 入队，距离设为 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                    q.append((i, j))

        # BFS 四个方向
        dirs = [(1,0), (-1,0), (0,1), (0,-1)]
        while q:
            x, y = q.popleft()
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    if dist[nx][ny] > dist[x][y] + 1:
                        dist[nx][ny] = dist[x][y] + 1
                        q.append((nx, ny))

        return dist


# 测试
if __name__ == "__main__":
    mat = [[0,0,0],[0,1,0],[1,1,1]]
    sol = Solution()
    result = sol.updateMatrix(mat)
    print(result)   # [[0,0,0],[0,1,0],[1,2,1]]