class Solution {
public:

    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        #define pii pair<int,int>
        #define fi first
        #define se second
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

        vector<vector<int>> vis(n, vector<int>(m));

        //first and last column
        for(int i=0; i<n; i++){
            vis[i][0] = 1;
            vis[i][m-1] = 1;
            pq.push({height[i][0], {i, 0}});
            pq.push({height[i][m-1], {i, m-1}});
        }
        //first and last row
        for(int i=0; i<m; i++){
            vis[0][i]=1;
            vis[n-1][i]=1;
            pq.push({height[0][i], {0, i}});
            pq.push({height[n-1][i], {n-1, i}});
        }
        int ans=0;
        while(!pq.empty()){
            int h = pq.top().fi;
            int r = pq.top().se.fi;
            int c = pq.top().se.se;
            pq.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    ans+=max(0, h-height[nr][nc]);
                    pq.push({max(h, height[nr][nc]), {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};
