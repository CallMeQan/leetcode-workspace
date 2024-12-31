#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    if (n <= 1){
        cout << n << " is NOT prime" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cnt++;
    }

    if (cnt > 2){
        cout << n << " is NOT prime" << endl;
    }
    else{
        cout << n << " is prime" << endl;
    }
    return 0;
}
