#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int FIB[46];
    FIB[0]=1;
    FIB[1]=1;
    for(int i=2;i<=45;++i)
        FIB[i]=FIB[i-1]+FIB[i-2];
    
    while(cin>>N){
        cout<<FIB[N]<<endl;
    }
    return 0;
}