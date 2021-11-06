#include <iostream>
using namespace std;


int get_int(){
    int x; cin >> x;
    return x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int W=0;
    for(int i=0;i<2;++i){
        int M = 0, C = 0;
        for(int j=0;j<4;++j)M += get_int();
        for(int j=0;j<4;++j)C += get_int();
        cout << M << ':' << C << '\n';
        W += (M > C ? 1 : -1);
    }
    switch(W){
    case 0:
        cout << "Tie" << '\n';
        break;
    case 2:
        cout << "Win" << '\n';
        break;
    case -2:
        cout << "Lose" << '\n';
        break;
    }
    return 0;
}