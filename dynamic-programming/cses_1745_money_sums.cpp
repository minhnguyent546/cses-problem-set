/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 17:27:00
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
    int max_v = accumulate(arr.begin(), arr.end(), 0);
    vector<bool> dp(max_v + 1);
    dp[0] = true;
    for (int value : arr) {
        for (int i = max_v; i >= value; --i) {
            if (dp[i - value] == true) {
                dp[i] = true;
            }
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0) - 1 << '\n';
    for (int i = 1; i <= max_v; ++i) {
        if (dp[i]) cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}
