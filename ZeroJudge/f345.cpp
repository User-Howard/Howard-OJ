#include<iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int arr[(int )1e6];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    for(int i=0;i<N;i++)
        cout<<arr[N-i-1]<<' ';
    cout<<endl;
    return 0;
}
