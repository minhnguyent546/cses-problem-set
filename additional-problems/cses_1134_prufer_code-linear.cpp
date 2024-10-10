/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-09-16 01:45:25
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
    vector<int> code(n - 2);
    for (int i = 0; i < n - 2; ++i) {
        cin >> code[i];
        --code[i];
    }

    vector<int> deg(n, 1);
    for (int i = 0; i < n - 2; ++i) {
        ++deg[code[i]];
    }

    int ptr = 0;
    while (deg[ptr] != 1) ++ptr;

    int leaf = ptr;

    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 2; ++i) {
        edges.emplace_back(leaf, code[i]);
        if (--deg[code[i]] == 1 && code[i] < ptr) {
            leaf = code[i];
        } else {
            ++ptr;
            while (deg[ptr] != 1) ++ptr;
            leaf = ptr;
        }
    }
    edges.emplace_back(leaf, n - 1);
    for (auto [u, v] : edges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    return 0;
}
