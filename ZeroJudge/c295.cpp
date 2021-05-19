#include<bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S;
    int arr[22];
    cin>>N>>M;
    S=0;
    for(int i=0;i<N;i++){
        int r, maxnum=-1;
        for(int j=0;j<M;j++){
            cin>>r;
            if(r>maxnum)
                maxnum = r;
        }
        arr[i] = maxnum;
        S+=maxnum;
    }
    cout<<S<<endl;
    bool any_cout = 0;
    for(int i=0;i<N;i++){
        if(S % arr[i] == 0){
            any_cout = 1;
            cout<<arr[i]<<' ';
        }
    }
    if(!any_cout)
        cout<<-1<<endl;
    else
        cout<<endl;

    return 0;
}