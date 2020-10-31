#include<iostream>
using namespace std;

int N;
string arr[102];
string change(string str, int x, char c){
    str[x] = c;
    return str;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int I, R;
    char si, sr;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    for(int i=0;i<N;i++){
        cin>>I>>R;
        si = arr[i][I-1];
        sr = arr[i][R-1];
        cout<<change(change(arr[i], I-1, sr), R-1, si);
        if(i!=N-1)
            cout<<' ';
        else
            cout<<'.';
    }
    cout<<endl;
    return 0;
}
