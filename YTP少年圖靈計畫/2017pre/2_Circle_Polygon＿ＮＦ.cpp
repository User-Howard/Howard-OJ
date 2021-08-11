#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.1415926


int main(){
    int N, L;
    while(cin >> N >> L){
        float rec = 180 / (N * 2);
        cout << setprecision(4) << L / (2 * cos(rec * PI / 180)) << '\n';
    }
    return 0;
}