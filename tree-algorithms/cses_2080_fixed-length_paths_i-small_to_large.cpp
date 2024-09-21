/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-08-21 23:13:53
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<vector<int>> freq(n); // freq of distance
    long long ans = 0;
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        freq[u].emplace_back(1); // freq[0] = 1, freq[u] is reversed, i.e. freq[i] = frequency of dist = size(freq[i]) - i - 1
        for (int v : g[u]) {
            if (v == par) continue;
            self(self, v, u);

            freq[v].emplace_back(0);
            int nu = (int) freq[u].size(), nv = (int) freq[v].size();
            if (nu < nv) {
                swap(freq[u], freq[v]);
                swap(nu, nv);
            }

            for (int i = 0; i < nv; ++i) {
                int rem = k - (nv - i - 1);
                if (0 <= rem && rem < nu) {
                    ans += 1LL * freq[u][nu - rem - 1] * freq[v][i];
                }
            }

            for (int i = 0; i < nv; ++i) {
                freq[u][nu - i - 1] += freq[v][nv - i - 1];
            }
        }
    };
    dfs(dfs, 0);
    cout << ans << '\n';
    
    return 0;
}
