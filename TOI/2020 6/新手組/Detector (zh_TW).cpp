#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int W, H;
    int arr[15][15];
    scanf("%d%d", &W, &H);
    int l=0, f=0;
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1)
                l++;
        }
    }
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(arr[i][j] == 5){
                bool tr=0;
                for(int h=-1;h<=1;h++){
                    for(int w=-1;w<=1;w++){
                        if((j+h) >= 0 && (j+h) < W && (i+w) >= 0 && (i+w) < H){
                            if(arr[i+h][j+w] == 5){
                                tr=1;
                            }
                        }
                    }
                }
            if(tr == 1)
                continue;
                for(int h=-1;h<=1;h++){
                    for(int w=-1;w<=1;w++){
                        if((j+h) >= 0 && (j+h) < W && (i+w) >= 0 && (i+w) < H){
                            if(arr[i+h][j+w] == 1){
                                arr[i+h][j+w] = 0;
                                f++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<f<<" "<<l-f<<endl;

    return 0;
}
