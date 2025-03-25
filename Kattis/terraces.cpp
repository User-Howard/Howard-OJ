#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;


const int MAX_N = 505;
const int INF = 1e9;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int N, M;
const int false_slot = MAX_N*1000;
int pool[MAX_N*1000+5];
int level[MAX_N*1000+5];
set<int> answer;
bool valid(int x, int y) {
    return x>=0 and y>=0 and x<N and y<M;
}
int find(int z) {
    if(z==false_slot) {
        return false_slot;
    }
    // cerr << "find " << z << '\n';
    if(pool[z]==z) return z;
    return pool[z] = find(pool[z]);
}
void solve(int z) {
    int x=z/1000, y=z%1000;
    for(int di=0;di<4;++di) {
        int tx = x+dx[di], ty = y+dy[di];
        int tz = 1000*tx+ty;
        if(not valid(tx, ty)) continue;
        if(level[z]==level[tz]) {
            if(find(z)==false_slot)
                pool[find(tz)] = find(z);
            else
                pool[find(z)] = find(tz);
        }
        else if(level[tz]<level[z])  {
            pool[find(z)] = false_slot;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            int z = 1000*i+j;
            cin >> level[z];
            pool[z] = z;
        }
    }
    pool[false_slot] = false_slot;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            int z = 1000*i+j;
            // cerr << "\t\t" << z << '\n';
            // {
            //     for(int i=0;i<N;++i) {
            //         for(int j=0;j<M;++j) {
            //             int z = 1000*i+j;
            //             cerr << pool[z]/1000 << "," << pool[z]%1000 << '\t';
            //         }
            //         cerr << '\n';
            //     }
            // }
            solve(z);
        }
    }
    int answer = 0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            int z = 1000*i+j;
            if(find(z)!=false_slot) answer++;
            // cerr << pool[z]/1000 << "," << pool[z]%1000 << '\t';
        }
        // cerr << '\n';
    }
    cout << answer << '\n';
    return 0;
}