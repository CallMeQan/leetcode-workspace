class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long f = accumulate(begin(grid[0]), end(grid[0]), 0LL), s = 0;
        long long mini = LONG_LONG_MAX;
        for (int i = 0; i < grid[0].size(); ++i) {
            f -= grid[0][i];
            mini = min(mini, max(f, s));
            s += grid[1][i];
        }
        return mini;
    }
};