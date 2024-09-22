/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:01:28
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
    int n;
    cin >> n;
    long long s = 1LL * n * (n + 1) / 2;
    if (s & 1) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    long long half = s / 2;
    vector<int> seen(n + 1);
    int cnt = 0;
    for (int i = n; i > 0; --i) {
        if (half >= i) {
            half -= i;
            seen[i] = true;
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; ++i) {
        if (seen[i]) cout << i << ' ';
    }
    cout << '\n';
    cout << n - cnt << '\n';
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}
