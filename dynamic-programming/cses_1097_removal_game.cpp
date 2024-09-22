/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 19:17:23
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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int s = n - 1; s >= 0; --s) {
        for (int e = s; e < n; ++e) {
            bool is_first = (n + e - s + 1) % 2 == 0;
            if (is_first) {
                if (s == e) dp[s][e] = arr[s];
                else dp[s][e] = max(dp[s + 1][e] + arr[s], dp[s][e - 1] + arr[e]);
            }
            else {
                if (s == e) dp[s][e] = -arr[s];
                else dp[s][e] = min(dp[s + 1][e] - arr[s], dp[s][e - 1] - arr[e]);
            }
        }
    }    
    long long s = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = (s + dp[0][n - 1]) / 2;
    cout << ans << '\n';
    return 0;
}

/*
def: dp[s][e] = first_player - second_player

first player: (n + e - s + 1) is even
    dp[s][e] = max{dp[s + 1][e] + arr[s], dp[s][e - 1] + arr[e]}  
    
second player: (n + e - s + 1) is odd
    dp[s][e] = min{dp[s + 1][e] - arr[s], dp[s][e - 1] - arr[e]}

a - b = dp[0][n - 1]
a + b = sum
a = (sum + dp[0][n - 1]) / 2
*/

