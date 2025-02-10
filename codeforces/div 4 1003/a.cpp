/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

void solve(){
    string w;
    cin>>w;
    w.pop_back();
    w.pop_back();
    cout<<w+"i"<<endl;
}

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        solve();
    }
}
