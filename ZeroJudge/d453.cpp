#include<iostream>
#include<string.h>
using namespace std;


int Times;
int sizeX, sizeY;
int sx, sy, ex, ey;
int doc[102][102];
bool puzzle[102][102];
void dfs(int, int, int);
void solve();


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>Times;
    while(Times--)
        solve();
    return 0;
}
void dfs(int i, int j, int NOW){
	if(puzzle[i][j]||i>=sizeX||i<0||j>=sizeY||j<0) return;

    if(doc[i][j]>NOW || doc[i][j] == 0){
        // cout<<NOW<<endl;
	    doc[i][j]=NOW;
	    dfs(i+1, j  , NOW+1);
	    dfs(i-1, j  , NOW+1);
	    dfs(i  , j+1, NOW+1);
	    dfs(i  , j-1, NOW+1);
    }
    return;
}
void solve(){
    cin>>sizeX>>sizeY>>sx>>sy>>ex>>ey;
    sx--,sy--,ex--,ey--;
    memset(doc, 0, sizeof(doc));
    memset(puzzle, 0, sizeof(puzzle));

    for(int i=0;i<sizeX;i++){
        string r;
        cin>>r;
        for(int j=0;j<sizeY;j++){
            puzzle[i][j]=(r[j] == '1');
        }
    }
    dfs(sx, sy, 1);
    cout<<doc[ex][ey]<<endl;
}