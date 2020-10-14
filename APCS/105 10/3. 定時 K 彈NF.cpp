#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N, M, K;
int arrb[MAXN];
int overPerson(int x, int step){
    int counter=0;
    for(int i=1;i<N*step;i++){
        if(arrb[(x+i)%N] == 1)
            counter++;
        if(counter == step)
            return (x+i)%N;
    }
    return -1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        arrb[i] = 1;
    }
    int point=-1;
    while(K--){
        point = overPerson(point, M);
        arrb[point] = 0;
    }
    cout<<overPerson(point, 1)+1<<endl;

    return 0;
}
