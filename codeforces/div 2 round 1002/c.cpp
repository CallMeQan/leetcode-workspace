/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> jth_moment(n+1, -1);
        vector<vector<int>> arr(n, vector<int>(n+1, 0));
        for(int i = 0; i<=n; i++){
            for(int j = 1; j<=n; j++){
                int num; cin>>num;
                arr[i][j] = arr[i][j-1] + num;
            }
        }
    }
}
