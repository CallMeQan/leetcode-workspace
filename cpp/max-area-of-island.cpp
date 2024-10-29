/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

/*

          FUCK THIS CODE
          THE IDEA IS VERY SIMPLE BUT FUCK THIS

*/

// ================ Code =============
#define pii pair<int,int>
#define fi first
#define se second
bool visited[51][51];
int moveX[4] = {1, 0,-1, 0};
int moveY[4] = {0, 1, 0,-1};

int bfs(pii a, vector<vector<int>>& grid){
    int res = 0;
    queue<pii> q;
    q.push(a);
    visited[a.fi][a.se] = true;

    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int x = cur.fi + moveX[i];
            int y = cur.se + moveY[i];
            if(grid[x][y] == 0 || visited[x][y]) continue;
            res++;
            q.push({x, y});
        }
    }
    return res;
}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 1; i<= grid.size(); i++){
            for(int j = 1; j <= grid[i].size(); j++){
                if(grid[i][j] == 0) continue;
                if(!visited[i][j]){
                    ans = max(ans, bfs({i, j}, grid));
                }
            }
        }
        return ans;
    }


// ================ End ==================

vector<vector<int>> parseInput(const string& input) {
    vector<vector<int>> result;
    vector<int> temp;
    stringstream ss(input);
    char ch;

    // Ignore the initial brackets [[
    ss >> ch >> ch;

    int number;
    while (ss >> number) {
        temp.push_back(number);

        // Skip over commas and spaces
        ss >> ch;
        if (ch == ']') {
            // End of row
            result.push_back(temp);
            temp.clear();
            // Skip next bracket if it's a closing bracket
            ss >> ch;
        }
    }
    return result;
}

signed main(){
    fast;
    int n, m;
    string userInput;
    getline(std::cin, userInput);
    vector<vector<int>> vec = parseInput(userInput);
    Solution s = Solution();
    cout<<s.maxAreaOfIsland(vec);
}
