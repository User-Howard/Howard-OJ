#include<iostream>
#include<algorithm>
using namespace std;


int main() {
    int N, M;
    int ans=0;
    while (cin >> N >> M){
        if(N==1)
            ans=1;
        else{
            if(N-M)
                ans = M+1;
            else
                ans = M;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
// finish time: 502	sec
