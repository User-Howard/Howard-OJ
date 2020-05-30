#include<iostream>
using namespace std;


int main(void){
    int N, Ans;
    scanf("%d",&N);
    if(N>0){
        Ans=(N*2)-1;
    }
    else{
        Ans=(-N*2);
    }
    printf("%d\n",Ans);
    return 0;
}