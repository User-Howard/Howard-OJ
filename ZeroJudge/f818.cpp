#include<iostream>
using namespace std;


const int MAX_N = 2e3 + 2;
const int INF = 0x3f3f3f3f;
int main(){
    int N;
    int H[MAX_N], W[MAX_N];

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>H[i];
    for(int i=0;i<N;i++)
        cin>>W[i];
    int min_lion=-1, min_size=INF;
    for(int i=0;i<N;i++){
        if(H[i]*W[i]<min_size){
            min_lion = i;
            min_size = H[i]*W[i];
        }
    }
    cout<<H[min_lion]<<' '<<W[min_lion]<<endl;
    return 0;
}