/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-10-04 23:58:15
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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + arr[i];
    }
    auto get = [&](int l, int r) -> long long {
        return pref[r + 1] - pref[l];
    };

    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<vector<long long>> dp(n, vector<long long>(n, INF));
    vector<vector<int>> opt(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
        opt[i][i] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = opt[i][j - 1]; k < j && k <= opt[i + 1][j]; ++k) {
                if (dp[i][j] >= dp[i][k] + dp[k + 1][j] + get(i, j)) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + get(i, j);
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    
    return 0;
}

/*
opt[i][j - 1] <= opt[i][j] <= opt[i + 1][j]
*/
