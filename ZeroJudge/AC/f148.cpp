#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int W, H, left;
    char NC, arr[10][10];
    scanf("%d%d%d", &W, &H, &left);
    int l=0;
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            cin>>arr[i][j];
            if(arr[i][j] != '0')
                l++;

        }
    }
    if(l < left){
        cout<<"Mission fail."<<endl;
        return 0;
    }

    NC='a';
    while(left > 0){
        for(int x=0;x<W;x++){
            for(int y=0;y<H;y++){
                if(arr[x][y] == NC){
                    cout<<x<<" "<<y<<endl;
                    left--;
                }
            }
        }
        NC++;
    }
    return 0;
}