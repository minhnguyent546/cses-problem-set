/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 11:55:02
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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i <= x; ++i) {
            if (arr[j] <= i) {
                dp[i] += dp[i - arr[j]];
                if (dp[i] >= MOD) dp[i] -= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
    
    return 0;
}
