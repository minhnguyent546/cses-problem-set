/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:08:25
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
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((2 * a - b) % 3 != 0) {
            cout << "NO" << '\n';
            continue;
        }
        int y = (2 * a - b) / 3;
        int x = a - 2 * y;
        if (y < 0 || x < 0) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }
    
    return 0;
}
