/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-22 00:38:07
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
    vector<array<int, 3>> arr(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) cin >> arr[i][j];
    }
    sort(arr.begin(), arr.end(), [](const auto &lhs, const auto &rhs) {
        return lhs[1] < rhs[1];
    });
    vector<int> end_times(n + 1);
    end_times[0] = 0;
    for (int i = 0; i < n; ++i) end_times[i + 1] = arr[i][1];
    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        int j = (int) (lower_bound(end_times.begin(), end_times.end(), arr[i - 1][0]) - end_times.begin());
        assert(j > 0);
        dp[i] = max(dp[i], arr[i - 1][2] + dp[j - 1]);
    }   
    cout << dp[n] << '\n';
    
    return 0;
}
