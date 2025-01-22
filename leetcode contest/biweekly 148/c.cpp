/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<pair<int, int>>> tree;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], length = edge[2];
            tree[u].emplace_back(v, length);
            tree[v].emplace_back(u, length);
        }

        vector<int> result = {0, 0}; // {longest_length, min_nodes}

        // Step 2: Perform BFS for each node
        for (int start = 0; start < n; ++start) {
            bfs(start, tree, nums, result);
        }

        return result;
    }
};

void printVec(vector<int> inp){
    for(int i = 0; i<inp.size(); i++){
        cout<<inp[i]<<" ";
    }
}
signed main(){
    fast;
    Solution s;
    vector<vector<int>> edges = {{0,1,2},{1,2,3},{1,3,5},{1,4,4},{2,5,6}};
    vector<int> nums = {2,1,2,1,3,1};
    printVec(s.longestSpecialPath(edges, nums));
}
