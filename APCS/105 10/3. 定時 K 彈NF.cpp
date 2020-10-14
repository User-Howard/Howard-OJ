#include<bits/stdc++.h>
using namespace std;


int N, M, K;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M>>K;
    int pointer=-1;

    for(int i=N;i>N-K;i--){
        pointer = (pointer+M)%i;
    }
    printf("%d %d %d \n", pointer, K*N, K*M);
    pointer = (pointer + K*N - K*M)%N;
    cout<<pointer;
    return 0;
}
// °Ñ¦Ò¦Û : http://yuihuang.com/zj-c296/
