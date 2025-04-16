#include <cmath>
#include <complex>
#include <iostream>
#include <vector>
#define int int64_t
using namespace std;

const int MAXN = 1<<21;
typedef long double ld;
typedef complex<ld> cplx;
const ld PI = acosl(-1);
const cplx I(0, 1);
cplx omega[MAXN + 1];
void pre_fft() {
    for (int i = 0; i <= MAXN; i++)
        omega[i] = exp(I * (2 * PI * i / MAXN));  // 正確的順序
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
    string s;
    cin >> s;
    int N = s.size();

    int len = 1;
    while (len < 2*N) len <<= 1;

    static cplx A[MAXN], B[MAXN];
    for (int i = 0; i < len; i++) {
        A[i] = cplx(0, 0);
        B[i] = cplx(0, 0);
    }
    for(int i=0;i<s.size();++i) {
        if(s[i]=='A') {
            A[N-i] = cplx(1, 0);
        } else {
            B[i] = cplx(1, 0);
        }
    }

    pre_fft();
    fft(len, A);
    fft(len, B);
    for (int i = 0; i < len; i++) A[i] *= B[i];
    fft(len, A, true);

    vector<int> result(len);
    for (int i = 0; i < len; i++) result[i] = round(A[i].real());
    for(int i=N-1;i>0;--i) {
        cout << result[i] << '\n';
    }
    return 0;
}