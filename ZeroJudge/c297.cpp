#include<bits/stdc++.h>
using namespace std;


int score = 0, f=0;
bool board[5];
string info[9][5];
/*
board[0] -> 本壘
board[1] -> 一壘
board[2] -> 二壘
board[3] -> 三壘
board[4] 用來計算得分
*/
void judge(){
    if(board[4] == 1){
        score++;
    }
    return;
}
void runover(int x){
    board[0] = 1;
    for(int r=0;r<x;r++){
        for(int i=4;i>0;i--){
            board[i] = board[i-1];
        }
        board[0] = 0;
        judge();
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int b;
    for(int i=0;i<9;i++){
        for(int j=0;j<5;j++){
            info[i][j] = "##";
        }
    }
    for(int player=0;player<9;player++){
        int a;
        cin>>a;
        for(int i=0;i<a;i++){
            cin>>info[player][i];
        }
    }
    cin>>b;
    for(int R=0;R<5;R++){
        for(int player = 0;player<9;player++){
            if(info[player][R] == "##")
                continue;

            if(info[player][R] == "1B"){
                runover(1);
            }
            else if(info[player][R] == "2B"){
                runover(2);
            }
            else if(info[player][R] == "3B"){
                runover(3);
            }
            else if(info[player][R] == "HR"){
                runover(4);
            }
            else{
                f++;
                b--;
                if(f == 3){
                    fill(board, board+5, 0);
                    f=0;
                }
                if(b == 0){
                    cout<<score<<endl;
                    return 0;
                }
            }
        }
    }
}