#pragma GCC optimize("Ofast,no-stack-protector")
#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
#define int long long
#define quick                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define rep(x, a, b) for (int x = a; x <= b; x++)
#define repd(x, a, b) for (int x = a; x >= b; x--)
#define lowbit(x) (x & -x)
#define sz(x) (int)(x.size())
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define mp make_pair
#define eb emplace_back
using namespace std;
typedef pair<int, int> pii;
void debug() { cout << "\n"; }
template <class T, class... U>
void debug(T a, U... b) {
    cout << a << " ", debug(b...);
}
const int INF = 1e18;

const int MAXN = 1 << 23;
typedef long double ld;
typedef complex<ld> cplx;
const ld PI = acosl(-1);
const cplx I(0, 1);
cplx omega[MAXN + 1];
void pre_fft() {
    for (int i = 0; i <= MAXN; i++) omega[i] = exp(I * (2 * PI * i / MAXN));
}
void fft(int n, cplx a[], bool inv = false) {
    int basic = MAXN / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            cplx w = omega[inv ? MAXN - (i * theta % MAXN) : i * theta % MAXN];
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                cplx x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta = (theta * 2) % MAXN;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    if (inv)
        for (i = 0; i < n; i++) a[i] /= n;
}
signed main() {
    quick int K, V;
    cin >> K >> V;
    int L = 1 << K;

    vector<double> p(V);
    vector<int> vote(V);
    vector<vector<double> > dp(V, vector<double>(L, 0));

    dp[0][0] = 1;
    for (int i = 0; i < V - 1; ++i) {
        cin >> p[i] >> vote[i];
        for (int j = 0; j < L; ++j) {
            dp[i+1][(j+vote[i])%L] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j]*(1.0-p[i]);
        }
    }

    vector<int> mask(L);
    for(int i=0;i<L;++i) {
        mask[i] = __builtin_popcount(i);
    }

    cplx A[L<<1], B[L<<1];
    for(int i=0;i<(L<<1);++i) {
        if(i<L) A[i] = cplx(dp[V-1][i], 0);
        else A[i] = cplx(0, 0);
    }
    for(int i=0;i<(L<<1);++i) {
        if(i<L) B[i] = cplx(mask[i], 0);
        else B[i] = cplx(mask[i-L], 0);
    }

    // cerr << "A:\n";
    // for(int i=0;i<L;++i) {
    //     // cerr << i << ": ";
    //     cerr << A[i].real() << '\t';
    // }
    // cerr << '\n';
    // cerr << "B:\n";
    // for(int i=0;i<L;++i) {
    //     // cerr << i << ": ";
    //     cerr << B[i].real() << '\t';
    // }
    // cerr << '\n';
    pre_fft();
    fft(L<<1, A);
    fft(L<<1, B);
    for(int i=0;i<(L<<1);++i) A[i] *= B[i];
    fft(L<<1, A, true);
    // cerr << "Sol:\n";
    // for(int i=0;i<(L<<1);++i) {
    //     cerr << i << ": " << A[i].real() << '\n';
    // }
    int min_id = 0;
    for(int i=1;i<L;++i) {
        if(A[i].real() < A[min_id].real()) {
            min_id = i;
        }
    }
    cout << L-min_id-1 << '\n';

    return 0;
}
