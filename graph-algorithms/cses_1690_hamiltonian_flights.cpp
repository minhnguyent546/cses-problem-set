/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-08-03 00:01:38
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
    }
    int sz = 1 << n;
    vector<vector<int>> dp(sz, vector<int>(n));
    int s = 0;
    dp[1 << s][s] = 1;
    auto has_bit = [&](int mask, int i) {
        return (mask >> i) & 1;
    };
    for (int mask = 0; mask < sz; ++mask) {
        if (!has_bit(mask, s)) continue;
        for (int i = 0; i < n; ++i) {
            if (has_bit(mask, i) && dp[mask][i] > 0) {
                for (int j : g[i]) {
                    if (!has_bit(mask, j)) {
                        dp[mask ^ (1 << j)][j] += dp[mask][i];
                        if (dp[mask ^ (1 << j)][j] >= MOD) dp[mask ^ (1 << j)][j] -= MOD;
                    }
                }
            }
        }
    }
    cout << dp[sz - 1][n - 1] << '\n';
    return 0;
}

/*
dp[mask][n] = number of ways to travel from vertex 1 to n, visit all nodes in mask exactly once
answer = dp[2^n - 1][n - 1]


*/
