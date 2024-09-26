/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-09-17 11:19:27
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int bipartite_matching(vector<vector<int>> &g, vector<int> &mat) {
    int n_left = (int) g.size();
    int n_right = (int) mat.size();
    vector<bool> used(n_left), pre_used(n_left);
    // finding some arbitrary matching to improve performance
    for (int u = 0; u < n_left; ++u) {
        for (int v : g[u]) {
            if (mat[v] == -1) {
                mat[v] = u;
                pre_used[u] = true;
                break;
            }
        }
    }
    auto find_aug_path = [&](auto &&self, int u) -> bool {
        if (used[u]) return false;
        used[u] = true;
        for (int v : g[u]) {
            if (mat[v] == -1 || self(self, mat[v])) {
                mat[v] = u;
                return true;
            }
        }
        return false;
    };
    for (int u = 0; u < n_left; ++u) {
        if (pre_used[u]) continue;
        fill(used.begin(), used.end(), false);
        find_aug_path(find_aug_path, u);
    }
    return n_right - count(mat.begin(), mat.end(), -1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n, vector<int>());
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
    }
    vector<int> mat(m, -1);
    int max_matching = bipartite_matching(g, mat);
    cout << max_matching << '\n';
    for (int v = 0; v < m; ++v) {
        if (mat[v] != -1) {
            cout << mat[v] + 1 << ' ' << v + 1 << '\n';
        }
    }
    
    return 0;
}
