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
    bool flag = false;
    int a[n+3];
    a[0] = 0;
    a[1] = 0;
    for(int i = 2; i<n; i++){
        cin>>a[i];
        if(a[i] == 1 && a[i-1] == 0 && a[i-2] == 1) flag = true;
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        solve();
    }
}
