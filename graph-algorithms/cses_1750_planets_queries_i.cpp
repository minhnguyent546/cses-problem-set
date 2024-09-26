/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-07-26 01:16:33
 **/           

// #undef _GLIBCXX_DEBUG

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
    int n, q;
    cin >> n >> q;
    const int LOG = 31;
    vector<vector<int>> target(LOG, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> target[0][i];
        --target[0][i];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            target[j][i] = target[j - 1][target[j - 1][i]];
        }
    }
    for (int w = 0; w < q; ++w) {
        int x, k;
        cin >> x >> k;
        --x;
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                x = target[i][x];
            }
        }
        cout << x + 1 << '\n';
    }
    return 0;
}
