#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, sum;
    int FIB[99999];
    FIB[0]=1;
    FIB[1]=1;
    for(int i=2;i<=99999;++i)
        FIB[i]=FIB[i-1]%1000000007+FIB[i-2]%1000000007;

    while(cin>>N>>K){
        sum=0;
        for(int i=N-2;i<=K-N;i++){
            cout<<FIB[i-1]<<endl;
            sum+=FIB[i-1];
            sum=sum%1000000007;
        }
        cout<<sum<<endl;
    }
    return 0;
}
