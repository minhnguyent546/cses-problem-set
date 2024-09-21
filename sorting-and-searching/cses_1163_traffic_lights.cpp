/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-07-16 15:01:17
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
    set<pair<int, int>> segments;
    multiset<int, greater<>> lengths;
    segments.emplace(n, 0);
    lengths.emplace(n);
    auto safe_erase = [&](auto &s, auto value) -> void {
        auto it = s.find(value);
        assert (it != s.end());
        s.erase(it);
    };  

    for (int i = 0; i < q; ++i) {
        int p;
        cin >> p;
        auto it = segments.lower_bound({p, -INF});
        auto [f, s] = *it;
        assert(it != segments.end() && it->first > p);
        safe_erase(lengths, it->first - it->second);
        safe_erase(segments, *it);
        segments.emplace(p, s);
        segments.emplace(f, p);
        lengths.emplace(p - s);
        lengths.emplace(f - p);
        cout << *lengths.begin() << ' ';
    }
    cout << '\n';
    
    return 0;
}
