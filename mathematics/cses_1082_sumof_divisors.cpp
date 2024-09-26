/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-24 20:54:04
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
    long long n;
    cin >> n;
    const int INV_2 = (MOD + 1) / 2;
    auto sum = [&](long long n) -> int {
        n %= MOD;
        return 1LL * n * (n + 1) % MOD * INV_2 % MOD;
    };
    int ans = 0;
    for (long long d = 1; d <= n; ++d) {
        long long next_d = n / (n / d);
        ans = (ans + 1LL * (n / d) * (sum(next_d) - sum(d - 1))) % MOD;
        if (ans < 0) ans += MOD;
        d = next_d;
    }
    cout << ans << '\n';
    
    return 0;
}
