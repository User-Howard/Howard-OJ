#include<iostream>
#include<string.h>
using namespace std;


int Times;
int sizeX, sizeY;
int doc[102][102];
bool puzzle[102][102];


void bfs(int i, int j, int NOW){
	if(puzzle[i][j]||i>=sizeX||i<0||j>=sizeY||j<0) return;
    if(doc[i][j]);
	doc[i][j]=NOW;
	bfs(i+1, j, NOW+1);
	bfs(i-1, j, NOW+1);
	bfs(i, j+1, NOW+1);
	bfs(i, j-1, NOW+1);
	return;
}


void solve(){
    cin>>sizeX>>sizeY;
    memset(doc, 10000, sizeof(doc));
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            // cin>>puzzle[i][j];
            printf("%d\n",doc[i][j]);
        }
    }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>Times;
    while(Times--)
        solve();
    return 0;
}