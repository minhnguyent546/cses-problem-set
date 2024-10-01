/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 23:18:26
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

inline long double pw(long double x, int e) {
    // using lesser multiplication operations to reduce errors
    long double ret = 1;
    while (e > 0) {
        if (e & 1) ret *= x;
        x *= x;
        e >>= 1;
    }
    // for (int i = 0; i < e; ++i) {
    //     ret *= x;
    // }
    return ret;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.precision(6); cout << fixed;
    cerr.precision(6); cerr << fixed;
    int n, k;
    cin >> n >> k;
    long double ans = 0;
    for (int i = 1; i <= k; ++i) {
        long double prod = pw((long double) i / k, n) - pw((long double) (i - 1) / k, n);
        ans += i * prod;
    }
    
    cout << ans << '\n';
    return 0;
}
