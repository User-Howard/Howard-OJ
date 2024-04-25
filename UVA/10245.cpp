#include <cinttypes>
#include <iomanip>
#include <ios>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define x first
#define y second


double dis(const pair<double, double> &A, const pair<double, double> &B) {
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}
int main() {
    int N;
    pair<double, double> Nums[10005];
    while(cin >> N and N) {
        for(int i=0;i<N;++i) {
            cin >> Nums[i].x >> Nums[i].y;
        }
        sort(Nums, Nums+N);
        double min_distance = 1e4;
        for(int i=0;i<N;++i) {
            for(int j=i+1;j<N;++j) {
                if(Nums[i].x + min_distance < Nums[j].x) break;
                min_distance = min(min_distance, dis(Nums[i], Nums[j]));
            }
        }
        if(min_distance >= 10000) {
            cout << "INFINITY\n";
        }
        else {
            cout << setprecision(4) << fixed << min_distance << '\n';
        }
    }
    return 0;
}
