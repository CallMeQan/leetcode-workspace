#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    int dec_value = 0;

    int base = 1;
    int tmp = n;
    while (tmp> 0) {
        int digit = tmp % 10;
        tmp = tmp / 10;
        dec_value += digit * base;
        base = base * 2;
    }
    cout<<dec_value<<endl;
}
