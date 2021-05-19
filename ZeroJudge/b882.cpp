#include<iostream>
using namespace std;


int main(void){
    long long int H, M, S;
    string Ans;
    scanf("%lld %lld %lld", &H, &M, &S);
    M+=S/60;
    H+=M/60;
    if(H%24<10)cout<<"0";
    cout<<H%24<<":";
    if(M%60<10)cout<<"0";
    cout<<M%60<<":";
    if(S%60<10)cout<<"0";
    cout<<S%60<<"\n";
    return 0;
}