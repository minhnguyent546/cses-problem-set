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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<vector<int>> freq(n);
    vector<vector<long long>> freq_pref(n); // freq of distance
    long long ans = 0;
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        freq[u].emplace_back(1);
        freq_pref[u].emplace_back(1); // freq[0] = 1, freq[u] is reversed, i.e. freq[i] = frequency of dist = size(freq[i]) - i - 1
        for (int v : g[u]) {
            if (v == par) continue;
            self(self, v, u);

            freq[v].emplace_back(0);
            freq_pref[v].emplace_back(freq_pref[v].back());
            int nu = (int) freq_pref[u].size(), nv = (int) freq_pref[v].size();
            if (nu < nv) {
                swap(freq[u], freq[v]);
                swap(freq_pref[u], freq_pref[v]);
                swap(nu, nv);
            }

            for (int i = 0; i < nv; ++i) {
                int d = nv - i - 1;
                int l = max(0, k1 - d);
                int r = min(nu - 1, k2 - d);
                if (l > r) continue;

                int lb = nu - r - 1;
                int rb = nu - l - 1;
                assert(0 <= lb && lb <= rb && rb < nu);
                long long cnt = freq_pref[u][rb] - (lb > 0 ? freq_pref[u][lb - 1] : 0);
                ans += 1LL * cnt * freq[v][i];
            }
            for (int i = 0; i < nv; ++i) {
                freq[u][nu - i - 1] += freq[v][nv - i - 1];
                freq_pref[u][nu - i - 1] += freq_pref[v][nv - i - 1];
            }
        }
    };
    dfs(dfs, 0);
    cout << ans << '\n';
    
    return 0;
}
