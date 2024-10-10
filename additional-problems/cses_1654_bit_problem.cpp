/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-09-02 20:45:08
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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int max_v = *max_element(arr.begin(), arr.end());
    vector<int> cnt(max_v + 1);
    for (int i = 0; i < n; ++i) {
        ++cnt[arr[i]];
    }

    int max_log = 32 - __builtin_clz(max_v);
    int m = 1 << max_log;
    vector<int> f(m), s(m);
    for (int mask = 0; mask < m; ++mask) {
        f[mask] = s[mask] = (mask <= max_v ? cnt[mask] : 0);
    }
    for (int i = 0; i < max_log; ++i) {
        for (int mask = 0; mask < m; ++mask) {
            if ((mask >> i) & 1) {
                int nmask = mask ^ (1 << i);
                f[mask] += f[nmask];
                s[nmask] += s[mask];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int inv = m - 1 - arr[i];
        cout << f[arr[i]] << ' ' << s[arr[i]] << ' ' << n - f[inv] << '\n';
    }
    
    return 0;
}
