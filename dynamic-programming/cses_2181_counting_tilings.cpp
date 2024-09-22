/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-09-18 18:43:32
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;

#define bit(mask, i) (((mask) >> (i)) & 1)

inline void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    else if (a < 0) a += MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    int M = 1 << n;
    vector dp(n, vector<int>(M));
    dp[n - 1][M - 1] = 1;
    for (int j = 1; j <= m; ++j) {
        vector next_dp(n, vector<int>(M));
        for (int i = 0; i < n; ++i) {
            for (int mask = 0; mask < M; ++mask) {
                if (bit(mask, i) == 0) {
                    // do nothing
                    if (i == 0) {
                        add(next_dp[i][mask], dp[n - 1][mask ^ (1 << i)]);
                    } else {
                        add(next_dp[i][mask], next_dp[i - 1][mask ^ (1 << i)]);
                    }
                } else {
                    if (i > 0 && bit(mask, i - 1)) {
                        // 2x1
                        if (i - 2 >= 0) {
                            add(next_dp[i][mask], next_dp[i - 2][mask]);
                        } else {
                            add(next_dp[i][mask], dp[n - 1][mask]);
                        }
                    } if (j > 1) {
                        // 1x2
                        if (i == 0) {
                            add(next_dp[i][mask], dp[n - 1][mask ^ (1 << i)]);
                        } else {
                            add(next_dp[i][mask], next_dp[i - 1][mask ^ (1 << i)]);
                        }
                    }
                }
            }
        }
        dp.swap(next_dp);
    }
    cout << dp[n - 1][M - 1] << '\n';
    
    return 0;
}

/*
dp[i][j][mask]
ans: dp[n - 1][m - 1][111..1111]

+ bit(mask, i) = 0
    + i > 0:
        dp[i][j][mask] = dp[i - 1][j][mask ^ (1 << i)]
    + i == 0:
        dp[i][j][mask] = dp[n - 1][j - 1][mask ^ (1 << i)]

+ bit(mask, i) = 1:
    + i > 0 && bit(mask, i - 1):
        + i - 2 >= 0:
            dp[i][j][mask] = dp[i - 2][j][mask]
        + otherwise
            dp[i][j][mask] = dp[n - 1][j - 1][mask]
    + j > 0:
        + i >= 0:
            dp[i][j][mask] = dp[i - 1][j][mask ^ (1 << i)]
        + otherwise:
            dp[i][j][mask] = dp[n - 1][j - 1][mask ^ (1 << i)]
*/

