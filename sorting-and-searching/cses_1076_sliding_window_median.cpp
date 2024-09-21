/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 16:06:16
 **/           
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename key_type>
using ordered_multiset = tree<key_type, null_type, less_equal<key_type>, rb_tree_tag,
    tree_order_statistics_node_update>;

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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ordered_multiset<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(arr[i]);
        if (i + 1 >= k) {
            cout << *s.find_by_order((k - 1) / 2) << ' ';
            s.erase(s.upper_bound(arr[i + 1 - k]));
        }
    }
    
    return 0;
}
