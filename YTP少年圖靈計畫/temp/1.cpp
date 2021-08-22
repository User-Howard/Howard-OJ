#include <iostream>
#include <string.h>
using namespace std;

bool is_prime[5002] = {0};
int main(){
    fill(is_prime + 2, is_prime+5002, 1);
    for(int i = 2;i < 5000;++i){
        if(is_prime[i]){
            for(int j = 2 * i;j < 5000;j += i){
                is_prime[j] = false;
            }
        }
    }
    int N;
    cin >> N;
    bool result = is_prime[N];
    for(int i = N;i > 0;--i){
        if(is_prime[i] == result)
            cout << i << ' ';
    }
    cout << '\n';
    return 0;
}