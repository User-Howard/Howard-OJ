#include <iostream>
using namespace std;


const int INF = 0x3f3f3f3f;
int A, B, C, D, M, S, T;
int max_length = -INF, min_time = INF;
int f(int x){
	// int min_time = (S - t * B) / A + t + max((t * C - M) / D, 0);
	int min_time = INF;
	for(int t=0;t*B<=S;++t){
		min_time = min(min_time, (S - t * B) / A + t + max((t * C - M) / D, 0));
		cout << (S - t * B) / A + t + max((t * C - M) / D, 0) << '\n';	
		cout << t * B + (T - t) * A + max(t * C - M, 0) / T << "\n\n";
	}
	return min_time;
}
int binary_search(int l, int r){
	if(r - l <= 1)
		return l;
	int mid = l + (r - l) / 2;
	if(f(mid) <= T) r = mid;
	else l = mid;
	return binary_search(l, r);
}
int main(){
	cin >> A >> B >> C >> D >> M >> S >> T;
	// cout << f(1) << '\n'; 
	for(int t=0;t*B<=S;++t){
		if((S - t * B) / A + t + max((t * C - M) / D, 0) >= T)
			min_time = min(min_time, (S - t * B) / A + t + max((t * C - M) / D, 0));
		cout << (S - t * B) / A + t + max((t * C - M) / D, 0) << '\n';
		max_length = max(max_length, t * B + (T - t) * A + max(t * C - M, 0) / T ); 
		cout << t * B + (T - t) * A + max(t * C - M, 0) / T << "\n\n";
		cout << '\n';
	}
	cout << min_time  << '\n' << max_length << '\n';
	return 0;
}
