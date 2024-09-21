/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 11:53:25
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
    int n, x;
    cin >> n >> x;
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        pref[i + 1] = pref[i] + value;
    }
    long long ans = 0;
    map<long long, int> count;
    count[0] = 1;
    for (int i = 1; i <= n; ++i) {
        long long remain = pref[i] - x;
        if (count.find(remain) != count.end()) {
            ans += count[remain];
        }
        cerr << i << ' ' << pref[i] << ' ' << pref[i] - x << ' ' << count[pref[i] - x] << '\n';
        count[pref[i]]++;
    }
    cout << ans << '\n';
    
    return 0;
}
