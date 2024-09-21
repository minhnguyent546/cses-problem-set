/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 16:59:58
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
    vector<pair<int, int>> times;
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;
        --t;
        times.emplace_back(s, 1);
        times.emplace_back(t + 1, -1);
    }
    sort(times.begin(), times.end());
    int ans = 0;
    int cur = 0;
    for (auto [time, delta] : times) {
        cur += delta;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    
    return 0;
}
