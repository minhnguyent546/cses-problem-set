/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-08-04 21:07:38
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
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            pref[r + 1][c + 1] = pref[r + 1][c] + pref[r][c + 1] - pref[r][c] + (grid[r][c] == '*');
        }
    }
    for (int w = 0; w < q; ++w) {
        int r, c, rr, cc;
        cin >> r >> c >> rr >> cc;
        cout << pref[rr][cc] - pref[r - 1][cc] - pref[rr][c - 1] + pref[r - 1][c - 1] << '\n';
    }
    return 0;
}
