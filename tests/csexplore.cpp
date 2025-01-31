#include <iostream>
using namespace std;

int main() {
    string n; cin>>n;
    int sum = 0;
    for(char c: n){
        if(c <= '9' && c >= '0'){
            cout<<sum<<" + "<<c<<" = ";
            sum += c - '0';
            cout<<sum<<endl;
        }
    }
    cout<<sum;
    return 0;
}
