/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

void solve(){
    string s; cin>>s;
    int n = s.length();
    if(n == 1){
        cout<<1<<endl;
        return;
    }
    for(int i = n - 1; i > 0; i--){
        if(s[i] == s[i-1]){
            cout<<n - i<<endl;
            return;
        }
    }
    cout<<n<<endl;
}

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        solve();
    }
}
