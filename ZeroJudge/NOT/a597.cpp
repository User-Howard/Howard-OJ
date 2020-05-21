#include<iostream>
#define TIMES 2
using namespace std;


int X,Y;
char arr[500][500];


bool de(int x, int y){

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
    cin>>X>>Y;
    for(int x=0;x<X;x++)
        for(int y=0;y>Y;y++)
            cin>>arr[x][y];


}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int limit=TIMES;
    while(limit--)
        solve();

    return 0;
}
