#include<iostream>
#include<string.h>
using namespace std;


int T, Case;
int sizeX, sizeY, sx, sy;
int doc[102][102];
bool puzzle[102][102];

void dfs(int i, int j, int NOW){
	if(puzzle[i][j]||i>=sizeX||i<0||j>=sizeY||j<0) return;

    // cout<<NOW<<endl;

    if(doc[i][j]>NOW || doc[i][j] == 0){

	    doc[i][j]=NOW;
	    dfs(i+1, j  , NOW+1);
        dfs(i  , j+1, NOW+1);
	    dfs(i  , j-1, NOW+1);
        if(T==1)
            dfs(i-1, j  , NOW+1);
    }
    return;
}


void solve(){
    cin>>sizeX>>sizeY;
    memset(doc, 0, sizeof(doc));
    memset(puzzle, 0, sizeof(puzzle));

    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            cin>>puzzle[i][j];
            puzzle[i][j]=!puzzle[i][j];
            if(i==0 and !puzzle[i][j]){
                sx=i;
                sy=j;
            }
        }
    }
    dfs(sx, sy, 1);
    
    cout<<"Case "<<Case<<":"<<endl;
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            cout<<doc[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Case=1;
    while(cin>>T){
        solve();
        Case++;
       
    }
     return 0;
}
