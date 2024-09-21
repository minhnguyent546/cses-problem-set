/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 21:35:40
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
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pref[i + 1] = val + pref[i];
    }

    deque<int> dq;
    auto Add = [&](int i) -> void {
        while (!dq.empty() && pref[dq.back()] >= pref[i]) dq.pop_back();
        dq.push_back(i);
    };  
    auto Remove = [&](int i) -> void {
        while (!dq.empty() && dq.front() <= i) dq.pop_front();
    };
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    long long ans = -INF;
    for (int i = 1; i <= n; ++i) {
        if (i - a >= 0) Add(i - a);
        if (!dq.empty()) {
            long long cur_best_sum = pref[i] - pref[dq.front()];
            ans = max(ans, cur_best_sum);
        }
        if (i - b >= 0) Remove(i - b);
    }
    cout << ans << '\n';
    
    return 0;
}
