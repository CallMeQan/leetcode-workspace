from typing import List

"""
You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.

Return the maximum number of moves that you can perform.
"""

class Solution:
    def DFS(self, x: int, y: int) -> int:
        moveRow = [-1, 0, 1]
        moveCol = [1, 1, 1]
        m, n = len(self.grid), len(self.grid[0])
        if y == n-1:
            return 1
        self.visited[x][y] = True
        ans = 0
        for i in range(3):
            nextX, nextY = x+moveRow[i], y+moveCol[i]
            if nextX >= 0 and nextX < m and nextY >= 0 and nextY < n and not self.visited[nextX][nextY] and self.grid[nextX][nextY] > self.grid[x][y]:
                ans = max(ans, 1+self.DFS(nextX, nextY))
        self.visited[x][y] = False
        return ans
        
    
    def maxMoves(self, grid: List[List[int]]) -> int:
        ans = 0
        self.grid = grid
        m, n = len(grid), len(grid[0])
        self.visited = [[False for _ in range(n)] for _ in range(m)]
        for i in range(m):
            ans = max(ans, self.DFS(grid, i, 0, m, n))
        return ans
        
if __name__ == '__main__':
    obj = Solution()
    grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
    print(obj.maxMoves(grid)) #3
    grid = [[3,2,4],[2,1,9],[1,1,7]]
    print(obj.maxMoves(grid)) #0