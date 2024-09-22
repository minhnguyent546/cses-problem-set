/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 14:38:28
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
    int q;
    cin >> q;
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        if (r >= c) {
            if (r & 1) {
                cout << 1LL * (r + 1) * (r + 1) - c << '\n';
            }
            else {
                cout << 1LL * r * r + 1 + c << '\n';
            }
        }
        else {
            if (c & 1) {
                cout << 1LL * c * c + 1 + r << '\n';
            }
            else {
                cout << 1LL * (c + 1) * (c + 1) - r << '\n';
            }
        }
    }
    
    return 0;
}
