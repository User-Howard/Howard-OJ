#include<iostream>
using namespace std;


char arr[3][3];
char judge(char arr[3][3]){
    for(char player='1';player<='2';player++){
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(arr[x][y] == player or arr[y][x] == player)
                    return player;
            }
        }
        if(arr[0][0] == player and arr[1][1] == player and arr[2][2] == player)
            return player;
        if(arr[0][2] == player and arr[1][1] == player and arr[2][0] == player)
            return player;
    }
    return -1;
}
int find(char arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j] == '-')
                return i*3+j;
        }
    }

}
void solve(char arr[3][3]){
    int idx = find(arr);
    if(idx == -1)
        return;
    
    
}
int main(){
    for(int i=0;i<9;i++){
        arr[i/3][i%3] = getchar();
    }
    cout<<(char)judge(arr)<<endl;
    return 0;
}