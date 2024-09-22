/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 14:31:53
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
    if (1 < n && n <= 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (n == 4) { 
        cout << "3 1 4 2" << '\n';
        return 0;
    }
    for (int t : {1, 2}) {
        for (int i = t; i <= n; i += 2) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    
    return 0;
}
