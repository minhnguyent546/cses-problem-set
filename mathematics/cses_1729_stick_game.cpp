/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-08-16 10:47:08
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
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> moves(k);
    for (int i = 0; i < k; ++i) {
        cin >> moves[i];
    }

    vector<bool> dp(n + 1);
    dp[0] = false;
    for (int i = 1; i <= n; ++i) {
        for (int m : moves) {
            if (m <= i && dp[i - m] == false) {
                dp[i] = true;
            }
        }
    }
    string ans(n, '?');
    for (int i = 1; i <= n; ++i) {
        ans[i - 1] = (dp[i] ? 'W' : 'L');
    }
    cout << ans << '\n';
    
    return 0;
}
