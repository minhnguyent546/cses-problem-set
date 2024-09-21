/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-09-14 20:25:37
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> d[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    long long reward = 0;
    long long cur_time = 0;
    for (int i = 0; i < n; ++i) {
        cur_time += a[order[i]];
        reward += d[order[i]] - cur_time;
    }
    cout << reward << '\n';    
    
    return 0;
}
