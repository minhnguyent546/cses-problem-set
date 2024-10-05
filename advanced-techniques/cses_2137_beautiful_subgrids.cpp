/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-12 00:09:28
 **/           
#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")

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
    int n;
    cin >> n;
    using Bit = bitset<3000>;
    vector<Bit> arr(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        arr[i] = Bit(s);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int ones = (arr[i] & arr[j]).count();
            ans += 1LL * ones * (ones - 1) / 2;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
