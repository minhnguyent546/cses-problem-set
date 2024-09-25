/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-08-04 20:47:38
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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pref[i + 1] = pref[i] ^ arr[i];
    }
    for (int w = 0; w < q; ++w) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << (pref[r + 1] ^ pref[l]) << '\n';
    }
    
    return 0;
}
