#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;
    if((N%2 == 0) and (N/2 >= 2))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}