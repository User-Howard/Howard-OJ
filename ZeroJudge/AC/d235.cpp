#include<iostream>
#include<algorithm>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T1, T2;
    string N;
    while(cin>>N, N!="0"){
        T1=0,T2=0;
        for(int i=0;i<N.size();i++){
            if(i%2 == 0)
                T1+=N[i]-'0';
            else
                T2+=N[i]-'0';
        }
        if(abs(T1-T2)%11 == 0){
            cout<<N<<" is a multiple of 11.\n";
        }
        else{
            cout<<N<<" is not a multiple of 11.\n";
        }
    }
    return 0;
}
