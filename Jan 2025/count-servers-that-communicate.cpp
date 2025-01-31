/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> cnt(m, 0), cnt2(n, -1);

        for (int row = 0; row < n; ++row) {
            int cntServer = 0;
            for (int col = 0; col < m; ++col)
                if (grid[row][col]) {
                    cntServer++;
                    cnt[col]++;
                    cnt2[row] = col;
                }
            if (cntServer != 1)
                ans += cntServer, cnt2[row] = -1;
        }

        for (int row = 0; row < n; ++row)
            ans += cnt2[row] != -1 && cnt[cnt2[row]] > 1;
        return ans;
    }
};

signed main(){
    fast;
    Solution s;

}
