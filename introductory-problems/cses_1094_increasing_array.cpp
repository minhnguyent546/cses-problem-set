/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 14:26:31
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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long cost = 0;
    int cur = arr[0];
    for (int i = 0; i < n; ++i) {
        cost += max(0, cur - arr[i]);
        cur = max(cur, arr[i]);
    }
    cout << cost << '\n';
    
    return 0;
}
