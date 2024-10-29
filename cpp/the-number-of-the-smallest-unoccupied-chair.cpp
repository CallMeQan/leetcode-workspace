/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int solve(vector<vector<int>> times, int targetFriend){
    int n = times.size();

    // Chairs
    priority_queue<int, vector<int>, greater<int>> chairs;
    // Leave
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

    int ans = -1;
    vector<pair<int,int>> bruhList;
    for(int i = 0; i<n; i++){
        bruhList.push_back({times[i][0], i})
    }
    sort(bruhList.begin(), bruhList.end());

    for(auto& a: bruhList){
        int fr = a[1];
        int aTime = a[0];


    }

    return ans;
}

signed main(){
    fast;
    int n, target;
    cin>>n>>target;
    vector<vector<int>> times;
    for(int i = 1; i<=n; i++){
        int s, e;
        cin>>s>>e;
        vector<int> tmp;
        tmp.push_back(s);
        tmp.push_back(e);
        times.push_back(tmp);
    }
    cout<<solve(times, target);
}
