/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

bool isValid(int row, int col, int numRows, int numCols) {
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));

        // Use deque for 0-1 BFS - add zero cost moves to front, cost=1 to back
        deque<pair<int, int>> deque;
        deque.push_front({0, 0});
        minCost[0][0] = 0;

        while (!deque.empty()) {
            auto [row, col] = deque.front();
            deque.pop_front();

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];
                int cost = (grid[row][col] != (dir + 1)) ? 1 : 0;

                // If position is valid and we found a better path
                if (isValid(newRow, newCol, numRows, numCols) &&
                    minCost[row][col] + cost < minCost[newRow][newCol]) {
                    minCost[newRow][newCol] = minCost[row][col] + cost;

                    // Add to back if cost=1, front if cost=0
                    if (cost == 1) {
                        deque.push_back({newRow, newCol});
                    } else {
                        deque.push_front({newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }
};

signed main(){
    fast;
    Solution s;

}
