/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 22:33:32
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
const long long INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long>> adj(n, vector<long long>(n, INF));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u][v] = min(adj[u][v], (long long) w);
    }
    auto mult = [&](const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
        vector<vector<long long>> ans(n, vector<long long>(n));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                long long min_v = INF;
                for (int g = 0; g < n; ++g) {
                    min_v = min(min_v, a[r][g] + b[g][c]);
                }
                ans[r][c] = min_v;
            }
        }
        return ans;
    };

    auto powmod = [&](vector<vector<long long>> a, long long e) {
        auto res = a;
        --e;
        while (e > 0) {
            if (e & 1) res = mult(res, a);
            a = mult(a, a);
            e >>= 1;
        }
        return res;
    };

    adj = powmod(adj, k);
    cout << (adj[0][n - 1] < INF ? adj[0][n - 1] : -1) << '\n';    
    return 0;
}
