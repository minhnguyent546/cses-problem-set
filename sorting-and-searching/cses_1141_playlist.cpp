/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-07-16 14:11:41
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
    int ans = 0;
    multiset<int> s;
    for (int i = 0, j = -1; i < n; ++i) {
        if (i > 0) {
            auto it = s.find(arr[i - 1]);
            assert(it != s.end());
            s.erase(it);
        }
        while (j + 1 < n && s.find(arr[j + 1]) == s.end()) {
            s.insert(arr[j + 1]);
            ++j;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';
    
    return 0;
}
