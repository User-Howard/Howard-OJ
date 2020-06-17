#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while(cin>>N){
        cout<<(N*N*N+5*N+6)/6<<endl;
    }
    return 0;
}