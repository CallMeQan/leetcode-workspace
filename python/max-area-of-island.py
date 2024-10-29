from typing import List


class Solution:
    def __init__(self):
        self.grid = []
    
    def dfs(self, i: int, j: int) -> int:
        if i < 0 or i >= len(self.grid) or j < 0 or j >= len(self.grid[0]) or self.grid[i][j] == 0:
            return 0
        self.grid[i][j] = 0 
        area = 1
        area += self.dfs(i + 1, j)
        area += self.dfs(i - 1, j)
        area += self.dfs(i, j + 1)
        area += self.dfs(i, j - 1)
        return area

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        max_area = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    max_area = max(max_area, self.dfs(i, j))
        return max_area
    
if __name__ == '__main__':
    s = Solution()
    print(s.maxAreaOfIsland([[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]])) # 6
    print(s.maxAreaOfIsland([[0,0,0,0,0,0,0,0]])) # 0