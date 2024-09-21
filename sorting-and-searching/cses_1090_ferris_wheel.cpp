/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 16:51:55
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());
    int ans = 0;
    for (int l = 0, r = n - 1; l <= r; ++l) {
        if (l < r && arr[l] + arr[r] <= k) {
            --r;
        }
        ++ans;
    }
    cout << ans << '\n';
    
    return 0;
}
