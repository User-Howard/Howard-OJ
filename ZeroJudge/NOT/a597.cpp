#include<iostream>
#define TIMES 1
using namespace std;


int Xr,Yr;
char arr[500][500];
int limit=TIMES;

bool check(int lx, int ly){
     // TODO ↓判斷是否在迴圈裡
    if((lx<0)or(ly<0)or(lx>Xr-1)or(ly>Yr-1))
        return 0;
    else
        return 1;
}


void de(int x, int y){
cout<<arr[1][1]<<endl;
cout<<"1";
    if(!check(x, y))
        return;
    if(arr[x][y] == 'X')
        return;
    else{
        arr[x][y] = 'X';
        de(x+1, y+0);
        de(x-1, y+0);
        de(x+0, y+1);
        de(x+0, y-1);

    }
}

void solve() {
    int maxim=0, pool=0;
    cin>>Xr>>Yr;
    for(int i=0;i<Xr;i++)
        for(int j=0;j>Yr;j++)
            cin>>arr[i][j];
    
    for(int i=0;i<Xr;i++){
        for(int j=0;j<Yr;j++){
            if(arr[i][j] == 'J'){
                de(i, j);
                pool++;
            }
        }
    }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(limit--)
        solve();

    return 0;
}
