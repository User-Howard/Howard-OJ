#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4;
int N, counti;
int arr[MAXN];
bool arr_check[MAXN];

void walk(int x){
    arr_check[x] = 1;
    if(arr_check[arr[x]] == 0)
        walk(arr[x]);
    return;
}
int blank(){
    for(int i=0;i<N;i++){
        if(arr_check[i] == 0){
            return i;
        }

    }
    return -1;

}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    fill(arr_check, arr_check+N, 0);
    counti=0;
    int run=0;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    do{
        counti++;
        walk(run);
        run = blank();
    }while(run != -1);
    cout<<counti;
}
