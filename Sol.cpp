#include <bits/stdc++.h>
using namespace std;

constexpr int kN = 1'000'000;

template <int kSz>
struct SegTree {
	static constexpr int kArr = kSz * 4;
	array<pair<int, int>, kArr> val;  // (max, min)
	array<int, kArr> flag;

	void Label(int id, int v) {
		val[id].first += v;
		val[id].second += v;
		flag[id] += v;
	}

	pair<int, int> Combine(pair<int, int> x, pair<int, int> y) {
		return {max(x.first, y.first), min(x.second, y.second)};
	}

	void Push(int id) {
		if (flag[id]) {
			Label(id * 2, flag[id]);
			Label(id * 2 + 1, flag[id]);
			flag[id] = 0;
		}
	}

	void Pull(int id) {
		val[id] = Combine(val[id * 2], val[id * 2 + 1]);
	}

	void Add(int ql, int qr, int v, int id = 1, int l = 0, int r = kSz - 1) {
		if (ql <= l && r <= qr) {
			Label(id, v);
		} else {
			int m = (l + r) / 2;
			Push(id);
			if (ql <= m) Add(ql, qr, v, id * 2, l, m);
			if (m < qr) Add(ql, qr, v, id * 2 + 1, m + 1, r);
			Pull(id);
		}
	}

	pair<int, int> Query(int ql, int qr, int id = 1, int l = 0, int r = kSz - 1) {
		if (ql <= l && r <= qr) return val[id];
		int m = (l + r) / 2;
		Push(id);
		if (qr <= m) return Query(ql, qr, id * 2, l, m);
		if (m < ql) return Query(ql, qr, id * 2 + 1, m + 1, r);
		return Combine(Query(ql, qr, id * 2, l, m),
		               Query(ql, qr, id * 2 + 1, m + 1, r));
	}
};
SegTree<kN> segtree;

int main() {
	cin.tie(nullptr), ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> as(n);
	vector<pair<int, int>> vals(n);  // (val, id)
	for (int i = 0; i < n; i++) cin >> as[i];
	for (int i = 0; i < n; i++) vals[i] = {as[i], i};
	sort(vals.begin(), vals.end());
	int q; cin >> q;
	vector<tuple<int, int, int, int, int>> queries(q);  // (val, l, r, cnt, id)
	vector<int> ans(q);
	for (int j = 0; j < q; j++) {
		int v, l, r, c;
		cin >> v >> l >> r >> c;
		--l, --r;
		queries[j] = {v, l, r, c, j};
	}
	sort(queries.begin(), queries.end());
	for (int i = 0, j = 0; j < q; j++) {
		auto [v, l, r, c, id] = queries[j];
		r = r - k + 1;
		if (l > r) continue;
		while (i < n && vals[i].first <= v) {
			int pos = vals[i].second;
			int affect_l = max(pos - k + 1, 0), affect_r = pos;
			segtree.Add(affect_l, affect_r, 1);
			++i;
		}
		auto range = segtree.Query(l, r);
		ans[id] = range.second <= c && c <= range.first;
	}
	for (auto x : ans) cout << x << '\n';
}
