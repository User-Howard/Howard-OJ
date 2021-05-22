#include<iostream>
using namespace std;


int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N!=0 && (M==0 || N%M)) {
            cout << "Impossib1e!\n";
        }
        else {
            cout << "Ok!\n";
        }
    }
    return 0;
}