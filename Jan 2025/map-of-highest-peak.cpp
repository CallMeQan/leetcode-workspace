/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

bool isValidCell(pair<int, int> curr, int n, int m) {
    return curr.first >= 0 && curr.second >= 0 && curr.first < n &&
           curr.second < m;
}
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        #define pii pair<int,int>
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pii> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int moveX[4] = {0,0,1,-1};
        int moveY[4] = {1,-1,0,0};
        int cnt = 1;
        while(!q.empty()){
            int tmp = q.size();
            for(int i = 0; i<tmp; i++){
                pii curr = q.front();
                q.pop();
                for(int j = 0; j<4; j++){
                    int x = curr.first + moveX[j];
                    int y = curr.second + moveY[j];
                    if (isValidCell({x, y}, n, m) && ans[x][y] == -1) {
                        ans[x][y] = cnt;
                        q.push({x, y});
                    }
                }
            }
            cnt++;
        }
        return ans;
    }
};

signed main(){
    fast;
    Solution s;

}
