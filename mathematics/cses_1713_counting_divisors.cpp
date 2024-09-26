/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 11:16:48
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
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int ans = 1;
        for (int i = 2; i * i <= x; ++i) {
            int k = 0;
            while (x % i == 0) {
                x /= i;
                ++k;
            }
            ans *= (k + 1);
        }
        if (x > 1) ans *= 2;
        cout << ans << '\n';
    }
    
    return 0;
}
