/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 11:38:19
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
    int n, t;
    cin >> n >> t;
    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    long long l = 1, r = (long long) 1e18;
    auto good = [&](long long T) -> bool {
        long long total_prod = 0;
        for (int i = 0; i < n; ++i) {
            total_prod += T / times[i];
            if (total_prod >= t) return true;
        }
        return false;
    };
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (good(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
    
    return 0;
}
