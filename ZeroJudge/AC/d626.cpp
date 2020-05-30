#include<iostream>
#include<string.h>
using namespace std;


int N, x, y;
char arr[102][102];
void BFS(int ,int);


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>arr[i][j];
    
    cin>>x>>y;
    BFS(x, y);
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
    		cout<<arr[i][j];
		}
    	cout<<endl;
	}		
    		
    return 0;
}
void BFS(int x, int y){
    if(x<0 || y<0 || x>=N || y>=N) return;
    if(arr[x][y] == '+') return;
    arr[x][y]='+';
    
    
    BFS(x+1,y  );
    BFS(x-1,y  );
    BFS(x  ,y+1);
    BFS(x  ,y-1);
}
