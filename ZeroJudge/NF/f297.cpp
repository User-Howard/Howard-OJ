#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int arr[2002];
    int record[2002][2002];
    cin>>N;

    for(int i=0;i<N;i++)
        cin>>arr[i];

    for(int i=0;i<N;i++){

        for(int j=i;j>0;j--){
            if(arr[j-1] > arr[j])
                swap(arr[j], arr[j-1]);
        }
        for(int k=0;k<N;k++)
            record[i][k] = arr[k];
    }

    int Q, qi, qj;
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>qi>>qj;
        cout<<record[qi-1][qj-1]<<endl;
    }
    return 0;
}

