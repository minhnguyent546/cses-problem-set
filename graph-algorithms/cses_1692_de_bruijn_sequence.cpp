/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-09-25 17:11:15
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "01" << '\n';
        return 0;
    }
    --n;
    int m = 1 << n;
    vector g(m, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u = i & ~(1 << (n - 1));
        u <<= 1;
        g[i].emplace_back(u);
        g[i].emplace_back(u | 1);
    }
    for (int u = 0; u < m; ++u) {
        assert(g[u].size() % 2 == 0);
    }

    auto elerian_path = [&](int source) -> vector<int> {
        vector<int> stack, cur_edge(m), vers;
        stack.emplace_back(source);
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            while (cur_edge[u] < (int) g[u].size()) {
                stack.emplace_back(u);
                u = g[u][cur_edge[u]++];
            }
            vers.emplace_back(u);
        }
        reverse(vers.begin(), vers.end());
        return vers;
    };
    vector<int> vers = elerian_path(0);
    string ans(n, '0');
    for (int i = 1; i < (int) vers.size(); ++i) {
        ans += (char) ((vers[i] & 1) + '0');
    }
    cout << ans << '\n';
    return 0;
}
