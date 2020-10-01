#include<bits/stdc++.h>
using namespace std;

int N, d;
int arr[49][49];
int x, y;
void walk(int direction, int n=0){
    if(n == (N-1)*2+1)
        return;
    int step = (n/2)+1;
    switch(direction){
    case 0:
        for(int i=0;i<step;i++){
            y--;
            cout<<arr[x][y]<<" ";
        }

    case 1:
        for(int i=0;i<step;i++){
            x--;
            cout<<arr[x][y]<<" ";
        }

    case 2:
        for(int i=0;i<step;i++){
            y++;
            cout<<arr[x][y]<<" ";
        }

    case 3:
        for(int i=0;i<step;i++){
            x++;
            cout<<arr[x][y]<<" ";
        }
    }
    cout<<endl;
    walk((direction+1)%4, n+1);
    return;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>d;
    for(int row=0;row<N;row++){
        for(int column=0;column<N;column++){
            cin>>arr[row][column];
        }
    }
    x=N/2;y=N/2;
    cout<<arr[x][y];
    walk(d);
    return 0;
}
/*
5
1
24 9  10 11 12
23 8  1  2  13
22 7  0  3  14
21 6  5  4  15
20 19 18 17 16

1 1 2 2 3 3 4 4
0 1 2 3 4 5 6 7
0 0 1 1 2 2 3 3
*/
