/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-10-05 12:12:48
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const double PI = acos(-1);
using Comp = complex<double>;
int reverse_bit(int n, int lg) {
    int ret = 0;
    for (int i = 0; i < lg; ++i) {
        if ((n >> i) & 1) {
            ret |= (1 << (lg - i - 1));
        }
    }
    return ret;
}
void fft(vector<Comp> &a, bool invert = false) {
    int n = (int) a.size();
    int lg = 0;
    while ((1 << lg) < n) ++lg;
    for (int i = 0; i < n; ++i) {
        int rev_i = reverse_bit(i, lg);
        if (i < rev_i) swap(a[i], a[rev_i]);
    }
    for (int len = 2; len <= n; len *= 2) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        Comp w_base(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            Comp w(1);
            for (int j = i; j < i + len / 2; ++j) {
                Comp u = a[j], v = a[j + len / 2];
                a[j] = u + w * v;
                a[j + len / 2] = u - w * v;
                w *= w_base;
            }
        }
    }
    if (invert) for (int i = 0; i < n; ++i) a[i] /= n;
}
template<typename T, typename G>
vector<int64_t> mult(const vector<T> &a, const vector<G> &b) {
    vector<Comp> A(a.begin(), a.end()), B(b.begin(), b.end());
    int n = a.size(), m = b.size(), p = 1;
    while (p < n + m) p *= 2;
    A.resize(p), B.resize(p);
    fft(A, false);
    fft(B, false);
    for (int i = 0; i < p; ++i) {
        A[i] *= B[i];
    }
    fft(A, true);
    vector<int64_t> res(n + m - 1);
    for (int i = 0; i < n + m - 1; ++i) {
        res[i] = (int64_t) round(A[i].real());
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[m - i - 1];
    }
    auto c = mult(a, b);
    for (int i = 0; i < n + m - 1; ++i) {
        cout << c[i] << ' ';
    }
    cout << '\n';
    
    
    return 0;
}
