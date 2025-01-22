#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main() {
    srand(time(NULL));
    cout<<rand();
    return 0;
}
