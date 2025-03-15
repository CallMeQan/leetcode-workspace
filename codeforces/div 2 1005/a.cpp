/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    string t = "";
    int cnt0 = 0;
    int cnt1 = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            int prev = 1;
            ans++;
            for(int j = i+1; j<n; j++){
                if(s[j] == '1'){
                    cnt1++;
                    if(prev == 0){
                        ans++;
                        prev = 1;
                    }
                }else{
                    cnt0++;
                    if(prev == 1){
                        ans++;
                        prev = 0;
                    }
                }
            }
            if(cnt1 == n) ans=0;
            break;
        }else{
            cnt0++;
        }
    }
    cout<<ans<<endl;
    return;
}

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        solve();
    }
}
