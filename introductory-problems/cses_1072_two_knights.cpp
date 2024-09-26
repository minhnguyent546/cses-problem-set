/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 14:48:01
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
    for (int k = 1; k <= n; ++k) {
        int m = k * k;
        cout << 1LL * m * (m - 1) / 2 - 4LL * (k - 1) * (k - 2) << '\n';
    }
    
    return 0;
}
/*
consider two rectangles 2x3 and 3x2
*/
