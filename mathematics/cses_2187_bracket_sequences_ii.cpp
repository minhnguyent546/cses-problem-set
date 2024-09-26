/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-09-26 00:16:38
 **/            
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;

const int N = (int) 1e6 + 3;
int fact[N];

inline int powmod(int a, int e) {
    int ret = 1;
    while (e > 0) {
        if (e & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        e >>= 1;
    }
    return ret;
}

inline int inv(int a) { return powmod(a, MOD - 2); }

int C(int n, int k) {
    return 1LL * fact[n] * inv(fact[n - k]) % MOD * inv(fact[k]) % MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    int n;
    cin >> n;
    string prefix;
    cin >> prefix;
    if (n & 1) {
        cout << 0 << '\n';
        return 0;
    }
    int rem = (int) prefix.size();
    int already = 0;
    for (int i = 0, bal = 0; i < (int) prefix.size(); ++i) {
        bal += (prefix[i] == '(' ? 1 : -1);
        if (bal < 0) {
            cout << 0 << '\n';
            return 0;
        }
        if (prefix[i] == ')') already++;
    }
    rem -= already * 2;
    n -= 2 * already + 2 * rem;
    if (n < 0) {
        cout << 0 << '\n';
        return 0;
    }

    assert(n >= 0);
    n /= 2;
    assert(n >= 0 && rem >= 0);

    int h = C(2 * n + rem, n);
    int ans = 1LL * (rem + 1) * h % MOD * inv(n + rem + 1) % MOD;
    cout << ans << '\n';
    
    return 0;
}
