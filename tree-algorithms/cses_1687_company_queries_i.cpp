/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 08:52:14
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
    const int LOG = 21;
    vector<vector<int>> anc(LOG, vector<int>(n, -1));
    for (int i = 1; i < n; ++i) {
        int par;
        cin >> par;
        --par;
        anc[0][i] = par;
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            anc[j][i] = (anc[j - 1][i] != -1 ? anc[j - 1][anc[j - 1][i]] : -1);
        }
    }
    auto jump = [&](int u, int k) {
        for (int i = 0; i < LOG; ++i) {
            if ((k >> i) & 1) {
                u = anc[i][u];
                if (u == -1) break;
            }
        }
        return u;
    };
    for (int w = 0; w < q; ++w) {
        int u, k;
        cin >> u >> k;
        --u;
        int v = jump(u, k);
        cout << (v != -1 ? v + 1 : -1) << '\n';
    }
    
    return 0;
}
