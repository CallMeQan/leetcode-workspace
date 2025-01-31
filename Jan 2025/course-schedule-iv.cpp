class Solution {
public:
    void bfs(int n, vector<vector<int>>& prerequisites, unordered_map<int, vector<int>>& adj, vector<vector<bool>>& visited) {
        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto a : adj[node]) {
                    if (!visited[i][a]) {
                        visited[i][a] = true;
                        q.push(a);
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> visited(numCourses, vector<bool>(numCourses, false));
        bfs(numCourses, prerequisites, adj, visited);

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(visited[q[0]][q[1]]);
        }

        return answer;
    }
};