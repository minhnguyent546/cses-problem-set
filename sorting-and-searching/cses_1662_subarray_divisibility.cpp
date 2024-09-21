/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 12:02:23
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
    int n;
    cin >> n;
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pref[i + 1] = pref[i] + val;
    }
    map<int, int> cnt;
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int rem = pref[i] % n;
        if (rem < 0) rem += n;
        if (cnt.find(rem) != cnt.end()) {
            ans += cnt[rem];
        }
        cnt[rem]++;
    }
    cout << ans << '\n';
    return 0;
}
