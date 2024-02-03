#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


vector<uint64_t> table;
void build_table() {
    uint64_t answer = 0, tenp = 1;
    int t = 1;
    table.emplace_back(0);
    while(answer < (uint64_t)1e18) {
        answer += 9*t*tenp;
        t++;
        tenp*=10;
        table.emplace_back(answer);
    }
}
int main() {
    int Q;
    uint64_t K;
    cin >> Q;
    build_table();
    while(Q--) {
        cin >> K;

        if(K<10) {
            cout << K << '\n';
            continue;
        }


        int digt = distance(table.begin(), prev(lower_bound(table.begin(), table.end(), K)));
        // cout << "D: " << digt << '\n';
        K -= table[digt];
        // cout << "K: " << K << '\n';
        if(K%(digt+1) == 0)
            cout << (K/(digt+1)-1)%10 << '\n';
        else {
            // cout << (uint64_t)powl(10, digt) + K/(digt+1)+1 << '\n';
            cout << to_string((uint64_t)powl(10, digt) + K/(digt+1))[K%(digt+1)-1] << '\n';
        }

    }
    return 0;
}