/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 14:10:02
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
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n & 1) {
            n = n * 3 + 1;
        }
        else {
            n /= 2;
        }
    }
    cout << 1 << ' ';
    return 0;
}
