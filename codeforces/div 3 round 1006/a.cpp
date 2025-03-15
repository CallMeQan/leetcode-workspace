/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
int n, k, p;

void solveNeg(){
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = -p; j<=0; j++)
        {
            sum+=j;
            cnt++;
            if(sum == k){
                cout<<cnt<<endl;
                return;
            }
        }
    }
    if(sum == k) cout<<cnt<<endl;
    else cout<<-1<<endl;
}

void solve(){
    cin>>n>>k>>p;
    if(k==0){
        cout<<0<<endl;
        return;
    }
    if(k<0){
        solveNeg();
        return;
    }

    int sum = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = p; j>=0; j--)
        {
            sum+=j;
            cnt++;
            if(sum == k){
                cout<<cnt<<endl;
                return;
            }
        }
    }
    if(sum == k) cout<<cnt<<endl;
    else cout<<-1<<endl;
}

signed main(){
    fast;
    int t;cin>>t;
    while(t--){
        solve();
    }
}
