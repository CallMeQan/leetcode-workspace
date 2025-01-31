/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

signed main(){
    fast;
    int t; cin>>t;
    while(t--){
        int n, val;
        bool flag = false;
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>val;
            if(val <= i*2 || val <= (n - i - 1) * 2) flag = true;
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
