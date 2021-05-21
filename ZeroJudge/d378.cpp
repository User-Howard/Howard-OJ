#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[102][102];
int solve(){
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>arr[i][j];
    for(int i=1;i<N;i++)
        arr[i][0] += arr[i-1][0];
    for(int i=1;i<M;i++)
        arr[0][i] +=arr[0][i-1];
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            arr[i][j] += min(arr[i][j-1], arr[i-1][j]);
        }
    }
    return arr[N-1][M-1];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases=0;
    while(cin>>N>>M){
        cout<<"Case #"<<(++cases)<<" :"<<'\n';
        cout<<solve()<<'\n';
    }
	return 0;
}
/*

*/
// finish time: 603	sec
