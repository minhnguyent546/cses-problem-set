/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-08-10 20:01:16
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    using Bit = bitset<30>;
    for (int i = 0; i < n; ++i) {
        string val;
        cin >> val;
        arr[i] = Bit(val).to_ullong();
    }
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int ones = __builtin_popcount(arr[i] ^ arr[j]);
            ans = min(ans, ones);
        }
    }
    cout << ans << '\n';
    
    return 0;
}
