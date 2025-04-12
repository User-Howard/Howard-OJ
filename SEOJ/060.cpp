#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
int A, B, C, D, M, S, T;
int max_length = -INF, min_time = INF;
ll f(int t){ // t秒內最多可以跑多遠？
	ll max_len = 0LL;
	for(int i=0;t-i-(max(i*C-M,0)+D-1)/D >= 0;++i){
		max_len = max(max_len, (1LL*i * B + (t-i-(max(i*C-M,0)+D-1)/D) * A));	
	}
	return max_len;
}
int binary_search(int l, int r) {
	while(r-l > 1) {
		int mid = (r + l) / 2;
		if(f(mid) < S) l = mid;
		else r = mid;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C >> D >> M >> S >> T;

	int ans = f(T);
	if(ans < S) {
		cout << "No" << '\n';
		cout << ans << '\n';
	} else {
		cout << "Yes" << '\n';
		cout << binary_search(0, T) << '\n';
	}
	return 0;
}
