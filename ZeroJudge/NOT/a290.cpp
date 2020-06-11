#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


int N, M, s1, s2, arr[802];
bool find(int N){

    return 1;
}
int main(void){
    while(scanf("%d %d", &N, &M) == 2){
        memset(arr, -1, sizeof(arr));
        while(scanf("%d %d",&s1, &s2) == 2){
            arr[s2] = s1;
        }
        cout<<arr[3];
    }

    return 0;
}
