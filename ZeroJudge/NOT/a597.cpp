#include<iostream>
#define TIMES 2
using namespace std;


int Xr,Yr;
char arr[500][500];


bool check(int lx, int ly){
    return;
}
bool de(int x, int y){
    // TODO ↓判斷是否在迴圈裡
    if((x<0)or(y<0)or(1))
    if(arr[x][y] == 'X')
        return 0;
    else{
        
        /*
        de(arr, x+1, y+0);
        de(arr, x-1, y+0);
        de(arr, x+0, y+1);
        de(arr, x+0, y-1);
        */
    }
}

void solve() {
    cin>>Xr>>Yr;
    for(int i=0;i<Xr;i++)
        for(int j=0;j>Yr;j++)
            cin>>arr[i][j];


}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int limit=TIMES;
    while(limit--)
        solve();

    return 0;
}
