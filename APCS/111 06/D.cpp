#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(N), Y(M);
    for(int &i:X) cin >> i;
    for(int &i:Y) cin >> i;

    int max_cross = -INF;
    for(int a=0;a<N;++a){
        for(int b=0;b<M;++b){
            int t1=0, t2=0;
            for(int d=0;a+d<N and b+d<M;++d){
                t1 += X[a+d]*Y[b+d];
                t2 += X[a+d]*Y[M-(b+d)-1];
                max_cross = max(max_cross, max(t1, t2));
            }
        }
    }
    cout << max_cross << '\n';
    return 0;
}