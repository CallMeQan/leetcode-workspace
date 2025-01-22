/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve(){
    map<int, int> a3guess;
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    a3guess[a1 + a2]++;
    a3guess[a4 - a2]++;
    a3guess[a5 - a4]++;
    int ans = 0;

    for (auto &[a, cnt] : a3guess){
        ans = max(ans, cnt);
    }
    cout << ans << '\n';

}

signed main(){
    fast;
    int t; cin>>t;
    while(t--) solve();
}
