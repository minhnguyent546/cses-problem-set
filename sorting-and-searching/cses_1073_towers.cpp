/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-07-16 14:39:45
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
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
    vector<int> dp;
    for (int i = 0; i < n; ++i) {
        int j = (int) (upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin());
        if (j == (int) dp.size()) {
            dp.emplace_back(arr[i]);
        }
        else {
            dp[j] = arr[i];
        }
    }
    cout << dp.size() << '\n';
    
    return 0;
}
