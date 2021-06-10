#include<iostream>
using namespace std;


const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int N, M;
int nums[10][10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> nums[i][j];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(nums[i][j]!=0){
                cout << nums[i][j] << ' ';
            }
            else{
                int cnt = 0, nu = 0;
                for(int way=0;way<4;way++){
                    int nx = i+dx[way], ny = j+dy[way];
                    if(nx<0||ny<0||nx>=N||ny>=M)
                        continue;
                    if(nums[nx][ny]!=0){
                        cnt+=nums[nx][ny];
                        ++nu;
                    }
                }
                if(nu==0)
                    cout << 0 << ' ';
                else
                    cout << cnt/nu << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
