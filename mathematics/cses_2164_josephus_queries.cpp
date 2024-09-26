/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-09-21 11:25:52
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
    #ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
    #endif
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        auto work = [&](auto &&self, int n, int k) -> int {
            assert(k <= n);
            if (n == 1) return 1;
            if (k <= (n + 1) / 2) {
                return (n & 1 ? (k * 2 % n) : k * 2);
            }
            if (n & 1) return 2 * self(self, n / 2, k - (n + 1) / 2) + 1;
            else return 2 * self(self, n / 2, k - n / 2) - 1;
        };
        cout << work(work, n, k) << '\n';
    }       
    
    return 0;
}
