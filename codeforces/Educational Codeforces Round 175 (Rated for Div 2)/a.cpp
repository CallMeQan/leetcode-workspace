/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

void solve(){
    int n;cin>>n;
    int cnt = 0;
    for(int i = 0; i<=2; i++){
        if(i>n) continue;
        cnt += (n-i)/15 + 1;
    }
    cout<<cnt<<endl;
}

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        solve();
    }
}
