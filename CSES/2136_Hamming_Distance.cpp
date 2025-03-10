#include <iostream>
#include <bitset>
using namespace std;


const int MAX_N = 2e4 + 5;
int N, K;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    bitset<30> bits[MAX_N];
    for(int i=0;i<N;++i) {
        string s;
        cin >> s;
        bits[i] = bitset<30>(s); 
    }

    int min_distance = 32;
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            int dis = (bits[i]^bits[j]).count();
            min_distance = min(min_distance, dis);
        }
    }
    cout << min_distance << '\n';
    return 0;
}