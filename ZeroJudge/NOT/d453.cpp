#include<iostream>
#include<string.h>
using namespace std;


int Times;
int sizeX, sizeY;
int sx, sy;
int ex, ey;
int doc[102][102];
bool Run;
bool puzzle[102][102];


void bfs(int i, int j, int NOW){
	if(puzzle[i][j]||i>=sizeX||i<0||j>=sizeY||j<0||(!Run)) return;

    if(doc[i][j]<NOW && doc[i][j] != 0){
	    doc[i][j]=NOW;
        if(i == ex and j == ey) Run=false;
	    bfs(i+1, j  , NOW+1);
	    bfs(i-1, j  , NOW+1);
	    bfs(i  , j+1, NOW+1);
	    bfs(i  , j-1, NOW+1);
    }
    return;
}


void solve(){
    cin>>sizeX>>sizeY>>sx>>sy>>ex>>ey;
    memset(doc, 0, sizeof(doc));
    memset(puzzle, 0, sizeof(puzzle));

    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            cout<<i+j;
            cin>>puzzle[i][j];
        }
    }
    Run=true;
    bfs(sx, sy, 1);
    cout<<doc[ex][ey]-1<<endl;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>Times;
    while(Times--)
        solve();
    return 0;
}