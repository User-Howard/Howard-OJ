#include<iostream>
#include<algorithm>
#include<stdio.h>
int n, m;
bool slove(){
    int a, b;
    int arr[n];
    int r=1;
    for(int _=0;_<m;_++, r++){
        scanf("%d %d", &a, &b);
        if(arr[b-1] == 0) swap(a, b);

        if(arr[a-1]==0 and arr[b-1]==0){
            arr[a-1] = r;
            arr[b-1] = r;
        }
        else if(arr[a-1]==0 and arr[b-1]!=0){
            arr[a-1] = arr[b-1];
        }
        else if(arr[a-1]!=0 and arr[b-1]!=0){
            int rest = arr[b-1];
            for(int i=0;i<n;i++){
                if(arr[i] == rest){
                    arr[i] = arr[a-1];
                }
            }
        }
    }

    return 0;
}
int main(void){
    int Case=1;
    while(scanf("%d %d", &n, &m) == 2 and n!=0){

    }
    return 0;
}
