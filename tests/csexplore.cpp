#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int row, columms, number = 1, n = 5;
    for(row = 0; row <=n; row++){
        for(columms = 0; columms<row; columms++){
            cout<<number<<" ";
            number++;
        }
        cout<<endl;
    }
    return 0;
}
