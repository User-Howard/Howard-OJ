#include<iostream>
#include<algorithm>
using namespace std;

int N, B, A[(int )1e5+2];
void solve(){
    cin>>N>>B;
    for(int i=0;i<N;++i)
        cin>>A[i];
    sort(A, A+N);
    int answer=0;
    for(int i=0;i<N;++i){
        if(B>=A[i]){
            ++answer;
            B-=A[i];
        }
    }
    cout<<answer<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int T;
    cin>>T;
    for(int c=1;c<=T;++c){
        cout<<"Case #"<<c<<": ";
        solve();
    }
    return 0;
}
