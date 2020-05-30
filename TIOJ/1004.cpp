#include<iostream>
#define PASS while(arr[r%N] == 0)r+=1;
using namespace std;

int N, arr[50];
int Lastpeople(){
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=(arr[i] == 1);
    }
    return sum;
}

int main(void){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        arr[i]=1; 
    for(int r=1, i=1; i<N ;r++, i++){
        PASS
        arr[r%N]=0;
        PASS
        cout<<"e"<<endl;
    }
    
    for(int i=0;i<N;i++)
        if(arr[i] == 1)
            cout<<i+1<<endl;
    return 0;
}