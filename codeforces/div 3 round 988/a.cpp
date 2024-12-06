/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

// Insert default

void solve(){
    int n, ans = 0;
    cin>>n;
    set<int> s;
    while(n--){
        int x; cin>>x;
        if(s.count(x)){
            ans++;
            s.erase(x);
        }else{
            s.emplace(x);
        }
    }
    cout<< ans<<endl;
}

signed main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
