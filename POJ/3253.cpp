#include<iostream>
using namespace std;


const int MAX_N = 5e4 + 2;
int N;
int arr[MAX_N];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    return 0;
}