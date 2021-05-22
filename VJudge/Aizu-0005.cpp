#include<iostream>
#include<cmath>
using namespace std;


int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}

int main(){
    int A, B;
    while(cin>>A>>B){
        cout<<gcd(A, B)<<' '<<lcm(A, B)<<'\n';
    }
    return 0;
}