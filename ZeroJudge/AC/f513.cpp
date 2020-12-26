#include<iostream>
using namespace std;


int main(){
    int N, M;
    int arr[102][102];
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>arr[i][j];
    
    int answer=M*N;
    const int dx[8]={-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[8]={1, 1, 1, 0, 0, -1, -1, -1};
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            bool any_same=false;
            for(int way=0;way<8;way++){
                int nx=r+dx[way], ny=c+dy[way];
                if(nx<0||ny<0||nx==N||ny==M)
                    continue;
                if(arr[nx][ny]==arr[r][c])
                    any_same=true;
            }
            // if(!any_same)
            //     printf("(%d, %d)\n", r, c);
            answer-=any_same;
        }
    }
    cout<<answer<<endl;
    return 0;
}