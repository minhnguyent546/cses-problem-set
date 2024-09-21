/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 11:39:52
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int remain = x - arr[i] - arr[j];
            if (mp.find(remain) != mp.end()) {
                cout << mp[remain] + 1 << ' '  << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
        mp[arr[i]] = i;
    }
    cout << "IMPOSSIBLE" << '\n';
    
    return 0;
}
