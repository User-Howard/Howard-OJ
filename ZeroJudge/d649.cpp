#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while(cin>>N and N){
        for(int f=1;f<=N;f++){
            for(int i=0;i<N-f;i++)
                cout<<"_";
            for(int i=0;i<f;i++)
                cout<<"+";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}