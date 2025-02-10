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
        int n; cin>>n;
        int a[n], b[n];
        map<int, int> m;

        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n; i++){
            cin>>b[i];
            for(int j = 0; j<n; j++){
                int c = b[i] + a[j];
                m[c]++;
            }
        }
        // Resulting
        if(m.size() < 3){
            cout<<"NO"<<endl;
            continue;
        }
        int cnt = 0;
        for(pair<int,int> i: m){
            if(i.second >= 2) cnt++;
            if(cnt>=3) break;
        }
        if(cnt < 3) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
