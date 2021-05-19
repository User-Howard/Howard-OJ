#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a1, a2, b1, b2, c1, c2, n;
    cin>>a1>>b1>>c1>>a2>>b2>>c2>>n;

    int ma = -1*(int )1e9;
    for(int i=0;i<=n;i++){
        int r;
        r = a1*i*i+b1*i+c1+a2*(n-i)*(n-i)+b2*(n-i)+c2;
        ma = max(ma, r);
    }
    cout<<ma<<endl;
    return 0;
}
