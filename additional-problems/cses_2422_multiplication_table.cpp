/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-10-03 00:43:15
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    long long low = 1, high = 1LL * n * n;
    auto good = [&](long long x) -> bool {
        long long le = 0;
        for (int i = 1; i <= min<long long> (n, x); ++i) {
            int j = min<long long>(x / i, n);
            le += j;
        }
        return 2 * le > 1LL * n * n;
    };
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (good(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << high << '\n';
    
    
    return 0;
}
