#include<iostream>
#include<string.h>
#define PASS while(arr[r%N] == 0)r+=1;
using namespace std;

int N, arr[50];
int Lastpeople(){
    int sum=0;
    for(int i=0;i<N;i++){
        // cout<<arr[i]<<" ";
        sum+=(arr[i] == 1);
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++)
        arr[i]=1; 

    for(int r=1;Lastpeople() != 1;r++){
        PASS
        arr[r%N]=0;
        PASS
    }
    
    // 輸出
    for(int i=0;i<N;i++)
        if(arr[i] == 1)
            cout<<i+1<<endl;
    return 0;
}