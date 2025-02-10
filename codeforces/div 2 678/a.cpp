/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

// Insert default

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int s = 0;
        for(int i = 1; i<=n; i++){
            int q;cin>>q;
            s += q;
        }
        if(s == m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
