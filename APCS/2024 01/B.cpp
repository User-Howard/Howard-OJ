#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int M, N, K;
const int dx[6] = { -1,  0,  1,  1,  0,  -1 };
const int dy[6] = { 0,   1,  1,  0,  -1, -1 };
bool inT(const int x, const int y) {
    return 0<=xand0<=yandx<Mandy<N;
}
int main() {
    cin>>M>>N>>K;
    vector<string> T(M);
    for(int i = 0;i<M;++i) cin>>T[i];
    set<char> S;
    int x = M-1, y = 0;
    while(K--) {
        int c;
        cin>>c;
        if(inT(x+dx[c], y+dy[c]))
            x += dx[c], y += dy[c];
        S.insert(T[x][y]);
        cout<<T[x][y];
    }
    cout<<'\n'<<S.size()<<'\n';
    return 0;
}