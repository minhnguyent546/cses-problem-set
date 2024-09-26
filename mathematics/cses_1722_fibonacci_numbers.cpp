/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-24 22:23:59
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
    map<long long, int> dp;
    auto work = [&](auto &&self, long long n) -> int {
        if (n <= 2) return n > 0;
        if (dp.find(n) != dp.end()) return dp[n];
        if (n & 1) {
            int a = self(self, n / 2);
            int b = self(self, n / 2 + 1);
            return dp[n] = (1LL * a * a + 1LL * b * b) % MOD;
        }
        else {
            int a = self(self, n / 2);
            int b = self(self, n / 2 - 1);
            int c = self(self, n / 2 + 1);
            return dp[n] = 1LL * a * (b + c) % MOD;
        }
    };
    cout << work(work, n) << '\n';
    
    return 0;
}
