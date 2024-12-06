#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

// Codeforces Round 975 (Div. 2)

void solve(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    int even = n/2;
    if(n % 2 != 0){
        even = n/2 + 1;
    }
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
