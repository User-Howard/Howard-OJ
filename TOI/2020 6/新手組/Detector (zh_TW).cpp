#include<iostream>
#include<stdio.h>
using namespace std;


int W, H;
int arr[15][15];
int find(int x){
    for(int i=0;i<W*H;i++){
        if(arr[i/W][i%W] == x)
            return  i;
    }
    return -1;
}
int find_block(int i, int j, int x){

    for(int h=-1;h<=1;h++){
        for(int w=-1;w<=1;w++){
            if((j+h) >= 0 && (j+h) < W && (i+w) >= 0 && (i+w) < H){
                if(h==0 and w==0)
                    continue;

                if(arr[i+h][j+w] == x){
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main(void){

    scanf("%d%d", &W, &H);
    int l=0, f=0;
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1)
                l++;
        }
    }
    while(find(5) != -1){
        int x=find(5)/W, y=find(5)%W;
        if(find_block(x, y, 4) or find_block(x, y, 5) or find_block(x, y, 6)){
            printf("config %d %d -> %d\n", x, y, 6);
            arr[x][y] = 6;
        }
        else{
            printf("config %d %d -> %d\n", x, y, 4);
            arr[x][y] = 4;
        }

    }
cout<<endl;
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
cout<<arr[i][j]<<" ";
            if(arr[i][j] != 1)
                continue;

            if(find_block(i, j, 4)){
                arr[i][j] = 0;
                f++;
            }
        }
cout<<endl;
    }
    printf("%d %d\n", f, l-f);
    return 0;
}
