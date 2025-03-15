/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
void solve(){
    int sum = 0;
    int ans = 0;
    int n; cin>>n;
    int a[n+1];
    a[0] = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    sum = a[1];
    if(sum % 2 == 0){
        ans++;
        while(sum % 2 == 0){
            sum /= 2;
        }
    }
    for(int i = 2; i<=n; i++){
        if(sum % 2 == 0){
            ans++;
            sum = sum+a[i];
            while(sum % 2 == 0){
                sum /= 2;
            }
        }else{
            sum += a[i];
        }
    }
    cout<<ans<<endl;
}

signed main(){
    fast;
    int t;cin>>t;
    while(t--){
        solve();
    }
}
