#include<iostream>
#include<string.h>
#include<algorithm>
#define TIMES 500
using namespace std;


int Xr, Yr, rest;
char arr[500][500];
int limit=TIMES;

bool check(int lx, int ly){
    if((lx<0)or(ly<0)or(lx>=Xr)or(ly>=Yr))
        return 0;
    else
        return 1;
}


void de(int x, int y){
// cout<<arr[1][1]<<endl;
// cout<<"1";
    if(!check(x, y))
        return;
    else if(arr[x][y] == 'X')
        return;
    else{
        rest++;
        arr[x][y] = 'X';
        de(x+1, y+0);
        de(x-1, y+0);
        de(x+0, y+1); 
        de(x+0, y-1);

    }
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>Xr>>Yr){
    int maxim=0, pool=0;
        memset(arr,true,sizeof(arr));
        for(int i=0;i<Xr;i++){
            string rest;
            cin>>rest;
            for(int j=0;j<Yr;j++){
                arr[i][j]=rest[j];
            }
        }
        for(int i=0;i<Xr;i++){
            for(int j=0;j<Yr;j++){
                rest=0;
                if(arr[i][j] == 'J'){
                    de(i, j);
                    pool++;
                    maxim=max(rest, maxim);
                }
            }
        }
         cout<<pool<<" "<<maxim<<endl;
    }

    return 0;
}
