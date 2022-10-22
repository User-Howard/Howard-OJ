#include <iostream>
#include <cmath>
using namespace std;


const int INF = 0x3f3f3f3f;
int A, B, C, D, M, S, T;
int max_length = -INF, min_time = INF;
int f(int t){ // t秒內最多可以跑多遠？
	// return (t * B + (T - t) * A + max(t * C - M, 0) * D);
	int max_len = -1;
	for(int i=0;t-i-ceil(1.0*max(i*C-M,0)/D) >= 0;++i){
		max_len = max(max_len, (i * B + (t - i - max(i * C - M, 0) / D) * A));	
	}
	return max_len;
}
int binary_search(int l, int r){
	if(r - l <= 1)
		return r;
	int mid = (r + l) / 2;
	// cout << "\n\n" << "l: " << l << '\t' << "r: " << r << '\n';
	// cout << mid << '\t' << f(mid) << '\n';
	if(S <= f(mid)) r = mid;
	else l = mid;
	return binary_search(l, r);
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
		cout << binary_search(-1, T) << '\n';
	}
	return 0;
}
