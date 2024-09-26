/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-08-02 23:49:30
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n), out(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        in[v]++;
        out[u]++;
    }

    if (out[0] - in[0] != 1 || in[n - 1] - out[n - 1] != 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for (int i = 1; i < n - 1; ++i) {
        if (in[i] != out[i]) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }            

    vector<int> cur_edge(n);
    vector<int> vertices, stack;
    int s = 0;
    stack.emplace_back(s);
    while (!stack.empty()) {
        int u = stack.back(); stack.pop_back();
        while (cur_edge[u] < (int) g[u].size()) {
            stack.push_back(u);
            u = g[u][cur_edge[u]++];
        }
        vertices.emplace_back(u);
    }
    if ((int) vertices.size() < m) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        reverse(vertices.begin(), vertices.end());
        for (int v : vertices) {
            cout << v + 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
