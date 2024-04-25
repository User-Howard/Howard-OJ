#include <iostream>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
using namespace std;
#define x first
#define y second


const int MAX_N =3e6 + 10;
pair<int, int> Nums[MAX_N];
double dis(const pair<int, int> &A, const pair<int, int> &B) {
    return sqrt(1LL*(A.x-B.x)*(A.x-B.x) + 1LL*(A.y-B.y)*(A.y-B.y));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> Nums[i].x >> Nums[i].y;
    }
    double min_distance = 2e7;
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            if(Nums[i].x + min_distance < Nums[j].x) break;
            min_distance = min(min_distance, dis(Nums[i], Nums[j]));
        }
    }
    cout << setprecision(4) << fixed << min_distance << '\n';
    return 0;
}
