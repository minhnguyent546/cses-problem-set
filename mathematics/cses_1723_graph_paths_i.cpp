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
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u][v]++;
    }

    const long long SMOD = 1LL * MOD * MOD;
    auto mult = [&](const vector<vector<int>> &a, const vector<vector<int>> &b) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                long long sum = 0;
                for (int g = 0; g < n; ++g) {
                    sum += 1LL * a[r][g] * b[g][c];
                    if (sum >= SMOD) sum -= SMOD;
                }
                ans[r][c] = sum % MOD;
            }
        }
        return ans;
    };

    auto powmod = [&](vector<vector<int>> a, long long e) {
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; ++i) res[i][i] = 1;
        while (e > 0) {
            if (e & 1) res = mult(res, a);
            a = mult(a, a);
            e >>= 1;
        }
        return res;
    };

    adj = powmod(adj, k);
    cout << adj[0][n - 1] << '\n';    
    return 0;
}
