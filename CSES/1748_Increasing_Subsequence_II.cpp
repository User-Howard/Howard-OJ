#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;


const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
template <typename T>
class BinaryIndexedTree {
private:
	vector<T> data;
public:
	BinaryIndexedTree(int n) { // use [1, n]
		data.resize(n+4);
	}
	void update(int pos, T val) {
		pos += 2;
		for(int i=pos;i<(int)data.size();i+=i&-i) {
			data[i] += val;
			data[i] %= mod;
		}
	}
	T query(int pos) {
		pos += 2;
		T result = 0;
		for(int i=pos;i>0;i-=i&-i) {
			result += data[i];
			result %= mod;
		}
		return result;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> Nums(N);
	for(auto &i: Nums) cin >> i;

	set<int> st(Nums.begin(), Nums.end());
	unordered_map<int, int> mp;
	int rank = 1;
	for(const auto &i: st) {
	    mp[i] = rank++;
	}


	BinaryIndexedTree<int64_t> bt(maxn);
	bt.update(0, 1);
	int64_t ans = 0;
	for(int num: Nums) {
		int64_t q = bt.query(mp[num]-1);
		bt.update(mp[num], q);
		ans = (ans + q) % mod;
	}
	cout << ans << '\n';
	return 0;
}
