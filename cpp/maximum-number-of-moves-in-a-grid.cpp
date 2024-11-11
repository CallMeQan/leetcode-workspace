#include <bits/stdc++.h>
using namespace std;

int row[]={-1,0,1};
int col[]={1,1,1};

class Solution
{
public:
    int bfs(vector<vector<int>> &grid, int n, int m, vector<vector<bool>> &visited, int i, int j){
        queue<pair<pair<int,int>, int>> q;
        visited[i][j] = true;
        q.push({{i, j}, 0});
        int res = 0;

        while(!q.empty()){
            pair<pair<int,int>,int> qPop = q.front();
            int a = qPop.first.first;
            int b = qPop.first.second;
            int cnt = qPop.second;

            q.pop();
            res = max(res, cnt);
            for(int i = 0; i<3; i++){
                int newRow = a + row[i];
                int newCol = b + col[i];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] > grid[a][b]){
                    visited[newRow][newCol] = true;
                    q.push({{newRow, newCol}, cnt + 1});
                }
            }
        }
        return res;
    }

    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            ans = max(ans, bfs(grid, n, m, visited, i, 0));
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    cout << sol.maxMoves(grid) << endl; // 3
    return 0;
}
