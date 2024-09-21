/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 17:20:45
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
const long long INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long best = -INF;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += arr[i];
        best = max(best, cur);
        if (cur < 0) cur = 0;
    }
    cout << best << '\n';
    
    return 0;
}
