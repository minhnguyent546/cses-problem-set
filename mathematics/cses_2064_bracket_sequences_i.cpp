/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-24 21:36:26
 **/           
#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;
 
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    const int N = (int) 2e6;
    vector<int> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    auto powmod = [&](long long a, long long n, int mod = MOD) -> int {
        a %= mod;
        int res = 1;
        while (n > 0) {
            if (n & 1) res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    };
    auto inv = [&](int n) -> int {
        return powmod(n, MOD - 2);
    };
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << '\n';
        return 0;
    }
    n /= 2;
    int ans = 1LL * fact[2 * n] * inv(fact[n]) % MOD * inv(fact[n + 1]) % MOD;
    cout << ans << '\n';
    return 0;
}
