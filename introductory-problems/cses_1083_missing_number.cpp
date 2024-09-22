/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 14:16:30
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
    long long sum = 1LL * n * (n + 1) / 2;
    for (int i = 0; i < n - 1; ++i) {
        int val;
        cin >> val;
        sum -= val;
    }
    cout << sum << '\n';
    
    return 0;
}
