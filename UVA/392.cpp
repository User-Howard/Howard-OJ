#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int Nums[9];
    while(cin >> Nums[0]) {
        for (int i=1;i<9;++i) {
            cin >> Nums[i];
        }
        int first_number = 8;
        for (int i=0;i<9;++i) {
            if(!Nums[i]) continue;
            first_number = min(first_number, i);
        }
        if (first_number == 8) {
            cout << Nums[8] << '\n';
        }
        else {
            for (int i=first_number;i<9;++i) {
                if (!Nums[i]) continue;
                if (i == first_number) {
                    if(Nums[i] == -1) cout << '-';
                    else if(Nums[i] != 1) cout << Nums[i];
                }
                else {
                    if (Nums[i] > 0) cout << " + ";
                    else             cout << " - ";

                    if (abs(Nums[i]) != 1 or i==8)
                        cout << abs(Nums[i]);
                    if (i==8) continue;
                }

                if (i != 7) cout << "x^" << 8-i;
                else        cout << "x";
            }
            cout << '\n';
        }
    }
    return 0;
}
