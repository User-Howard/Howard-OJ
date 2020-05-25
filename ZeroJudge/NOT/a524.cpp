#include<iostream>
#include<string.h>
using namespace std;


int N, visited[9], arr[9];

bool in_(int li, int a){
    for(int i=0;i<li.size();i++)
        if(li[i] == a)
            return 1;
    return 0;
}
void R(int T){
    if(T == N)
        return;
    for(int i=N;i != 0;i--){
        if()
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    while(cin>>N){
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<N;++i){
            arr[i]=N-i;
        }
        for(int i=0;i<N;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}