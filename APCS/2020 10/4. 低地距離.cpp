#include<bits/stdc++.h>
using namespace std;


int main(){
    int N;
    long int sum = 0;
    int arr[(int )2e5];
    int walk[(int )1e5];
    cin>>N;
    for(int i=0;i<2*N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<2*N;i++){
        if(walk[arr[i]] == 0){
            for(int j=1;i+j<2*N;j++){
                if(arr[i+j] == arr[i])
                    break;
                if(arr[i+j] < arr[i])
                    sum++;
            }
            walk[arr[i]] = 1;
        }
    }
    cout<<sum<<endl;
    return 0;
}
