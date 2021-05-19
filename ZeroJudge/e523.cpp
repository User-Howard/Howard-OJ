#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool inthe;
    int N, Q, FIB[46];
    FIB[0]=1;
    FIB[1]=1;
    for(int i=2;i<=45;++i)
        FIB[i]=FIB[i-1]+FIB[i-2];

    cin>>N;
    while(N--){
        cin>>Q;
        inthe=0;
        for(int i=0;i<46;i++){
            if(FIB[i] == Q){
                cout<<i+1<<endl;
                inthe=1;
                break;
            }
            
        }
        if(!inthe)
            cout<<-1<<endl;
    }
    return 0;
}