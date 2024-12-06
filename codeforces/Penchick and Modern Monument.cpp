#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// Codeforces Round 987 (Div. 2)

const int N = 51;
const int INF = 1e9+7;

void solve(){
    int n;
    cin>>n;
    int a[n+1];
    unordered_map<int, int> mp;
    int k = -1;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        mp[a[i]]++;
        k = max(k, mp[a[i]]);
    }
    cout<<n-k<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
