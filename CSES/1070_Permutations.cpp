#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin>>N;
    if(2<=N and N<=3)
        cout<<"NO SOLUTION"<<'\n';
    else {
        for(int i=2;i<=N;i+=2)
            cout << i << ' ';
        for(int i=1;i<=N;i+=2)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
