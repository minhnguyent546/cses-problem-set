/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 17:17:38
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map<int, int> mapping;
    for (int i = 0; i < n; ++i) {
        if (mapping.find(x - arr[i]) != mapping.end()) {
            cout << mapping[x - arr[i]] + 1 << ' ' << i + 1 << '\n';
            return 0;
        }
        mapping[arr[i]] = i;
    }
    cout << "IMPOSSIBLE" << '\n';
    
    return 0;
}
