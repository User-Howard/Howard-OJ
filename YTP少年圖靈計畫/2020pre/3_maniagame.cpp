#include <iostream>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R, C;
    string S[1002];
    cin >> R >> C;
    getline(cin, S[0], '\n');   // clear '\n'
    for(int i=0;i<R;i++)
        getline(cin, S[i], '\n');
    int ans = 0;
    for(int i=0;i<C;i++){
        int e = 0;
        while(e<R){
            if(S[e][i]=='X'){
                ++ans;
                while(e<R && S[e][i]=='X')++e;
            }
            else ++e;
        }
    }
    cout << ans << '\n';
    return 0;
}