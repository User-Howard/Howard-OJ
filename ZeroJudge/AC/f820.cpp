#include<iostream>
using namespace std;


#define nextpointer pointer + decision
int main() {
    int N, T;
    int arr [32];
    cin >> N;
    for (int i = 1;i <= N;i++)
        cin >> arr [i];
    cin >> T;

    int decision = -1;
    if (T == 1 || (T != N && arr [T+1] < arr [T-1]))
        decision = 1;
    int last_altitude = arr[T];
    int pointer=T;
    while(!(nextpointer==0 || nextpointer==N+1) && arr[nextpointer]<=last_altitude){
        pointer = nextpointer;
        last_altitude = arr[pointer];
    }
    cout<<pointer<<endl;
    return 0;
}