/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 16:14:14
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;

    auto calc_len = [&](long long n) -> long long {
        long long len = 0;
        for (long long d = 1; d <= n; d *= 10) {
            len += n - d + 1;
        }
        return len;
    };
    while (q--) {
        long long k;
        cin >> k;
        long long l = 1, r = k;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (calc_len(mid) >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        string repr = to_string(r);
        cout << repr[repr.length() - (calc_len(r) - k) - 1] << '\n';

    }
    
    return 0;
}
