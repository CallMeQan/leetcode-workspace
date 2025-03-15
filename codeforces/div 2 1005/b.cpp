/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n];
    map<int,int> m;
    int ans = 0;
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        a[i] = num;
        m[num]++;
        ans = max(0LL, m[num] - num);
    }
    for(pair<int, int> it : m){
        cout << "key = " << it.first << ", value = " << it.second << endl;
    }
    cout<<ans<<endl;
}

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        solve();
    }
}
