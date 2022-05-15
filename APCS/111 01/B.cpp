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
	// ios::sync_with_stdio(0); cin.tie(0);
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
		if(v.size()%2)
			v1.push_back(v.back());
		for(int i=0;(i+1)*2<=v.size();++i){
			uint64_t a = S[v[2*i]], b = T[v[2*i]], c = S[v[2*i+1]], d = T[v[2*i+1]];
			uint64_t da, db, dc, dd;
			// cout << "S: ";
			// for(int64_t j:S)
			// 	cout << j << ' ';
			// cout << '\n';
			// cout << "T: ";
			// for(int64_t j:T)
			// 	cout << j << ' ';
			// cout << '\n';
			if(a*b >= c*d){
				da = c * d / (2 * b), db = c * d / (2 * a);
				dc = c / 2, dd = d / 2;
				++loss[2*i+1];
				v1.push_back(v[2*i]);
				if(loss[2*i + 1] < M){
					v2.push_back(v[2*i + 1]);
				}
			}
			else{
				dc = a * b / (2 * d), dd = a * b / (2 * c);
				da = a / 2, db = b / 2;
				++loss[2*i];
				v1.push_back(v[2*i+1]);
				if(loss[2*i] < M){
					v2.push_back(v[2*i]);
				}
			}
			S[2*i] = a + da, T[2*i] = b + db;
			S[2*i + 1] = c + dc, T[2*i + 1] = d + dd;
		}
		v = v1;
		for(uint64_t i:v2)
			v.push_back(i);
		// cout << "V: ";
		// for(int64_t j:v)
		// 	cout << j << ' ';
		// cout << '\n';
		// cout << "L: ";
		// for(int64_t j:loss)
		// 	cout << j << ' ';
		// cout << '\n';
		// cout << '\n';
		v1.clear();
		v2.clear();
	}
		cout << v[0]+1 << '\n';
	
	return 0;
}
// 60.33