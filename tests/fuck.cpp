#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for (int i = 2; i <= n/2; i++) {
        bool isPrime1 = true;
        bool isPrime2 = true;

        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                isPrime1 = false;
                break;
            }
        }

        for (int j = 2; j*j <= (n-i); j++) {
            if ((n-i) % j == 0) {
                isPrime2 = false;
                break;
            }
        }
        if (isPrime1 && isPrime2) {
            cout<<i<<endl;
            cout<<n-i<<endl;
            return 0;
        }
    }

        cout<<"Invalid"<<endl;
        return 0;
}
