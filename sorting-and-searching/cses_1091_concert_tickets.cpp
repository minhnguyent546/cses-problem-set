/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 16:57:08
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        s.insert(v);
    }
    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        auto it = s.upper_bound(t);
        if (it == s.begin()) {
            cout << -1 << '\n';
        }
        else {
            --it;
            cout << *it << '\n';
            s.erase(it);
        }
    }
    
    return 0;
}
