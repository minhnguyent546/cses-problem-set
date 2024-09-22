/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 11:52:03
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
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= coins[j]) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    cout << (dp[x] < INF ? dp[x] : -1) << '\n';

    
    return 0;
}
