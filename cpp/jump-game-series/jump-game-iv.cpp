#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        #define pii pair<int, int>
        #define fi first
        #define se second
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<pii> q;
        q.push({0, 0});
        int ans = 1e9;

        while (!q.empty())
        {
            pii p = q.front();
            q.pop();

            int pos = p.se;
            int cnt = p.fi;

            visited[pos] = true;
            if (pos == n - 1)
            {
                ans = min(ans, cnt);
            }
            if (pos + 1 < n && !visited[pos + 1])
            {
                q.push({cnt + 1, pos + 1});
            }
            if (pos - 1 >= 0 && !visited[pos - 1])
            {
                q.push({cnt + 1, pos - 1});
            }

            for (auto &it : mp[arr[pos]])
            {
                if (!visited[it])
                {
                    q.push({cnt + 1, it});
                }
            }
            mp[arr[pos]].clear();
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    Solution s;
    cout << s.minJumps(nums) << endl; // true
}

/*
Time Complexity: O(n)
- Each element is processed a constant number of times.
- The BFS ensures that each node (index) is visited at most once.

Space Complexity: O(n)
- The space used by the queue, visited array, and the map is proportional to the number of elements in the array.
*/
