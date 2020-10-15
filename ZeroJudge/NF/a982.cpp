#include<iostream>
#include<queue>

using namespace std;

int N;
char arr[102][102];
queue<pair<int, int>>que;
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%c", &arr[i][j]);
        }
    }


    return 0;
}
