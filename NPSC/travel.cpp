#include <iostream>
using namespace std;


const int MAX_N = 1e5+2;
const int MAX_Mi = 1e2+2;
int N, S, T;
int road[MAX_N][MAX_Mi] = {0};
int write[MAX_N] = {0};
int M[MAX_N];
void walk(int atwhere, int step=1){
    if(step==T+1)
        goto ret;
    cout<<atwhere<<endl;
    walk(road[atwhere][(write[atwhere]++)%M[atwhere]], step+1);
ret:
    return;
}
int main(){
    cin>>N>>S>>T;
    for(int i=0;i<N;++i){
        cin>>M[i];
        for(int j=0;j<M[i];++j){
            cin>>road[i][j];
        }
    }
    walk(S);
    return 0;
}