/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 17:02:56
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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --b;
        arr[i] = {a, b};    
    }
    sort(arr.begin(), arr.end(), [](const auto &lhs, const auto &rhs) {
        if (lhs.second == rhs.second) {
            return lhs.first > rhs.first;
        }
        return lhs.second < rhs.second;
    });
    int ans = 0;
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (prev == -1 || arr[i].first > arr[prev].second) {
            ++ans;
            prev = i;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
