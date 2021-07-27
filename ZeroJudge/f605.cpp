#include<iostream>
#include<algorithm>
using namespace std;



const int MAX_N = 1e2+2;
int main(){
    int N, D;
    int arr[MAX_N][3];
    cin >> N >> D;
    for(int i=0;i<N;i++)
        for(int j=0;j<3;j++)
            cin >> arr[i][j];
    int count = 0, money = 0;
    for(int i=0;i<N;i++)
        if(max(max(arr[i][0], arr[i][1]), arr[i][2]) - min(min(arr[i][0], arr[i][1]), arr[i][2]) >= D){
            ++count;
            money += (arr[i][0] + arr[i][1] + arr[i][2]) / 3;
        }
    cout << count << ' ' << money << endl;
    return 0;
}