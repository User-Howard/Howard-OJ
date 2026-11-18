#include <iostream>
#include <vector>
using namespace std;


const int mod = 1e9 + 7;;
const int maxn = 10;
const int maxm = 1000 + 2;
int main() {
	int N, M;
	cin >> N >> M;
    vector<int> cur(1<<N), nxt(1<<N);
    fill(cur.begin(), cur.end(), 0);
    cur[0] = 1;
	for(int i=0;i<M;++i) {
		for(int j=0;j<N;++j) {
            fill(nxt.begin(), nxt.end(), 0);
			for(int s=0;s<(1<<N);++s) {
                if(s>>j&1) {
                    int ns = s^(1<<j);
                    nxt[ns] = (nxt[ns] + cur[s]) % mod;
                } else {
                    if (i + 1 < M) {
                        int ns = s|(1<<j);
                        nxt[ns] = (nxt[ns] + cur[s]) % mod;
                    }
                    if (j + 1 < N && !(s >> (j + 1) & 1)) {
                        int ns = s|(1<<(j+1));
                        nxt[ns] = (nxt[ns] + cur[s]) % mod;
                    }
                }
			}
            swap(cur, nxt);
		}
	}
    cout << cur[0] << '\n';

	return 0;
}
