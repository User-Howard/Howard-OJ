#include<iostream>
#define FOR(i, x) for(int i=0;i<x;i++)
using namespace std;

int cmp(string a, string b){
    if (a.size()!=b.size())
        return a.size() < b.size();
    
    for(int i=0;i<a.size();i++){
        if (a[i]!=b[i])
            return a[i] < b[i];
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string A, B;
    cin>>N;
    while(N--){
        cin>>A>>B;
        cout<<cmp(A, B)<<endl;
    }
    return 0;
}