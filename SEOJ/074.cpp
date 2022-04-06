#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N, num, np = -1, direction = 1;
        cin >> N;
        int cnt = 0;
        for(int i=0;i<N;++i){
            cin >> num;
            if(direction*np < direction*num){
                direction *= -1;
                ++cnt;
            }
            np = num;
            // cout << np << '\t' << direction << '\n';
        }
        if(direction == 1)
            --cnt;
        cout << cnt << '\n';
    }
    return 0;
}