/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-08-04 20:49:48
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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    const int LOG = 21;
    vector<vector<int>> table(LOG, vector<int>(n));
    table[0] = arr;
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int w = 0; w < q; ++w) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int i = __lg(r - l + 1);
        cout << min(table[i][l], table[i][r - (1 << i) + 1]) << '\n';
    }
    
    return 0;
}
