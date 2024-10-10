/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-10-02 22:39:46
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int n = 3;
bitset<(int) 1e9> vis;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int start = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            start = start * 10 + x;
        }
    }

    int target = 123456789;
    vector<int> pw(9);
    pw[0] = 1;
    for (int i = 1; i < 9; ++i) {
        pw[i] = pw[i - 1] * 10;
    }

    vector<pair<int, int>> que = {pair{start, 0}};
    vis[start] = true;
    auto SW = [&](int u, int i, int j) {
        i = 9 - i - 1;
        j = 9 - j - 1;
        int digit_i = (u / pw[i]) % 10;
        int digit_j = (u / pw[j]) % 10;
        u += (digit_j - digit_i) * pw[i];
        u += (digit_i - digit_j) * pw[j];
        return u;
    };

    for (int k = 0; k < (int) que.size(); ++k) {
        auto [u, dist] = que[k];
        if (u == target) {
            cout << dist << '\n';
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + 1 < n) {
                    int v = SW(u, i * n + j, i * n + j + 1);
                    if (!vis[v]) {
                        que.emplace_back(v, dist + 1);
                        vis[v] = true;
                    }
                }
                if (i + 1 < n) {
                    int v = SW(u, i * n + j, (i + 1) * n + j);
                    if (!vis[v]) {
                        que.emplace_back(v, dist + 1);
                        vis[v] = true;
                    }
                }
            }
        }
    }
    assert(false);
    return 0;
}
