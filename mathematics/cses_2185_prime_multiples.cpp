/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 15:56:10
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
    int k;
    cin >> n >> k;
    vector<long long> primes(k);
    for (int i = 0; i < k; ++i) {
        cin >> primes[i];
    }
 
    long long ans = n;
    for (int mask = 0; mask < (1 << k); ++mask) {
        int ones = __builtin_popcount(mask);
        long long prod = 1;
        bool bad = false;
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) & 1) {
                if (primes[i] > n / prod) {
                    bad = true;
                    break;
                }
                prod *= primes[i];
            }
        }
        if (bad) continue;
        ans += (ones & 1 ? n / prod : -n / prod);
    }
    cout << ans << '\n';
    
    return 0;
}
