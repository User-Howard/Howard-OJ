// NF
// https://zerojudge.tw/ShowProblem?problemid=h082
/*
1	0.05
2	0.05
3	0.05
*/
#include <iostream>
#include <vector>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<uint64_t> S(N), T(N), loss(N);
	vector<int64_t> v, v1, v2;
	for(uint64_t &i:S) cin >> i;
	for(uint64_t &i:T) cin >> i;
	for(int i=0;i<N;++i){
		int idx;
		cin >> idx;
		v.push_back(idx-1);
	}
	while(v.size() != 1){
		for(int i=0;i+1<v.size();i+=2){
			int x = v[i], y = v[i+1];
			uint64_t a = S[x], b = T[x], c = S[y], d = T[y];
			uint64_t da, db, dc, dd;
			if(a*b >= c*d){
				da = c * d / (2 * b), db = c * d / (2 * a);
				dc = c / 2, dd = d / 2;
				++loss[y];
				v1.push_back(x);
				if(loss[y] < M){
					v2.push_back(y);
				}
			}
			else{
				dc = a * b / (2 * d), dd = a * b / (2 * c);
				da = a / 2, db = b / 2;
				++loss[x];
				v1.push_back(y);
				if(loss[x] < M){
					v2.push_back(x);
				}
			}
			S[x] = a + da, T[x] = b + db;
			S[y] = c + dc, T[y] = d + dd;
		}
		if(v.size()%2)
			v1.push_back(v.back());
		v = v1;
		for(uint64_t i:v2)
			v.push_back(i);
		v1.clear();
		v2.clear();
	}
	cout << v[0]+1 << '\n';
	return 0;
}
// 60.33