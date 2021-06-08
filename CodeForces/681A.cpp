#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, before, after;
    string name;
    cin >> N;
    for(int cases=0;cases<N;cases++){
        cin >> name >> before >> after;
        if(2400<=before && before < after){
            cout << "YES" << '\n';
            goto END;
        }
    }
    cout << "NO" << '\n';
END:;
    return 0;
}