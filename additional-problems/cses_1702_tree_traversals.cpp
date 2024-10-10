/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-10-03 10:19:07
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
    vector<int> pre(n), in(n);
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
        --pre[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        --in[i];
    }

    vector<int> in_where(n);
    for (int i = 0; i < n; ++i) {
        in_where[in[i]] = i;
    }
    vector<array<int, 2>> g(n, {-1, -1});
    vector<int> post;
    auto construct = [&](auto &&self, int pre_first, int pre_last, int in_first, int in_last) -> void {
        if (pre_first >= pre_last) return;
        assert(pre_first < pre_last);
        assert(in_first < in_last);
        int root = pre[pre_first];
        int pos = in_where[root];
        self(self, pre_first + 1, pre_first + 1 + pos - in_first, in_first, pos);
        self(self, pre_last - (in_last - pos - 1), pre_last, pos + 1, in_last);
        post.emplace_back(root);
    };
    construct(construct, 0, n, 0, n);
    for (int u : post) {
        cout << u + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}
