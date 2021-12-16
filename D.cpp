#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
vvi LU(vvi v, int x){
    for(int i=0;i<v.size();++i)
        for(int j=0;j<v[0].size();++j)
            if(i <= x && j <= x && i+j>x)
                v[i][j] += v[x - j][x - i];

    for(int i=0;i<x;++i)
        for(int j=0;j<x-i;++j)
            v[i][j] = 0;

    return v;
}
vvi RU(vvi v, int x){
    for(int i=0;i<v.size();++i)
        reverse(v[i]);
    v = LU(v, x);
    for(int i=0;i<v.size();++i)
        reverse(v[i]);
    return v;
}
vvi LD(vvi v, int x){
    reverse(v);
    v = LU(v, x);
    reverse(v);
    return v;
}
vvi RD(vvi v, int x){
    reverse(v);
    v = RU(v, x);
    reverse(v);
    return v;
}
int main(){
    int N, M, x;
    cin >> N >> M;
    vvi v(N, vi(M));
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            cin >> v[i][j];
    cin >> x;
    v = RU(v, x);
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j)
            cout << v[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
