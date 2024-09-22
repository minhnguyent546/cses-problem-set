/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 12:08:33
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
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> grid[r][c];
        }
    }
    char obstacle = '*';
    vector<vector<int>> dp(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == obstacle) continue;
            if (r == 0 && c == 0) {
                dp[r][c] = 1;
                continue;
            }
            if (r > 0) dp[r][c] += dp[r - 1][c];
            if (c > 0) dp[r][c] += dp[r][c - 1];
            if (dp[r][c] >= MOD) dp[r][c] -= MOD;
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
    return 0;
}
