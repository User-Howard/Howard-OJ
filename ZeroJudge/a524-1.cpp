#include<iostream>
#include<string.h>
using namespace std;


int N, visited[9], arr[9];
void R(int T){
    if(T>N){
        for(int i=0;i<N;i++)
            cout<<arr[i];
        cout<<endl;
        return;
    }
    else{
        for(int i=N;i != 0;i--){
            if(visited[i])
                continue;
            arr[T-1]=i;
            visited[i]=1;
            R(T+1);
            visited[i]=0;
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    while(cin>>N){
        memset(visited, 0, sizeof(visited));
        R(1);
        
    }
    return 0;
}