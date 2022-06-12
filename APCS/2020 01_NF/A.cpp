#include <iostream>
#include <vector>
using namespace std;

struct E{
    int win, tie, lose;
}a[6];
int main(){
    a[0].win = 2;a[0].tie = 0;a[0].lose = 5;
    a[2].win = 5;a[2].tie = 2;a[2].lose = 0;
    a[5].win = 0;a[5].tie = 5;a[5].lose = 2;
    int F, N;
    cin >> F >> N;
    vector<int> Y(N);
    for(int &i:Y) cin >> i;
    for(int i=0;i<N;++i){
        if(i>0){
            if(i >= 2 and Y[i-2] == Y[i-1])
                F = a[Y[i-1]].lose;
            else
                F = Y[i-1];
        }
        cout << F << ' ';
        if(F != Y[i]){
            if(a[F].win == Y[i])
                cout << ": Won at round " << i+1 << '\n';
            else
                cout << ": Lost at round " << i+1 << '\n';
            goto END;
        }
    }
    cout << ": Drew at round " << N << '\n';
    END:;
    return 0;
}