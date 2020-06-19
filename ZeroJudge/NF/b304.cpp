#include<stdio.h>
#include<iostream>
using namespace std;


int W, H;
int arr[102][22];
string rest;

int dfs(int N){
    if(N>-1 and )
}


int main(void){
    while(scanf("%d %d", &W, &H) == 2){
        getchar();
        for(int i=0;i<H;i++){
            getline(cin, rest);
            for(int j=0;j<W*2-1;j++){
                arr[i][j]=rest[j];
            }
        }

        /*
        cout<<"da..."<<endl;
        for(int i=0;i<H;i++){
            for(int j=0;j<W*2-1;j++){
                cout<<(char)arr[i][j];
            }
            cout<<endl;
        }
        */
    }
    return 0;
}
