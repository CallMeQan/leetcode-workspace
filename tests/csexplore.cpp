#include <iostream>
using namespace std;

int resupply(int shortfall, int supply[5][5]) {
    int min_total = 3001;
    int supply_flat[25];
    int cnt = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            supply_flat[cnt] = supply[i][j];
            cnt++;
        }
    }
    cnt = 0;
    for(int i = 0; i<21; i++){
        for(int j = i+1; j<22; j++){
            for(int m = j+1; m<23; m++){
                for(int k = m+1; k<24; k++){
                    for(int h = k+1; h<25; h++){
                        int total = supply_flat[i] + supply_flat[j] + supply_flat[m]+supply_flat[k]+supply_flat[h];
                        if(total >= shortfall){
                            if(total < min_total){
                                min_total = total;
                            }
                        }
                        cnt++;
                        cout<<"Combinations #"<<cnt<<" "<<total<<endl;
                    }
                }
            }
        }
    }
    // O(25C5 * 25) = 1328250 don vi thoi gian
    // O(n*logn)
    cout<<min_total<<endl;
}

int main() {
    int n;cin>>n;
    int s[5][5];
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cin>>s[i][j];
        }
    }
    resupply(n, s);
}
