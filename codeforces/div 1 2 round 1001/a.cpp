/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve(){
    string s; cin>>s;
    int ans = 0;
    for(char c: s){
        if(c == '1') ans++;
    }
    cout<<ans<<'\n';
}

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        solve();
    }
}
