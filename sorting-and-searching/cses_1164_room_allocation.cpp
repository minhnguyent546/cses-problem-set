/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 11:20:03
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
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arr.emplace_back(a, b);
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&arr](int i, int j) {
        return arr[i].second < arr[j].second;
    });
    vector<int> ans(n);
    int room_cnt = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        int ptr = order[i];
        auto it = s.lower_bound({arr[ptr].first, -INF});
        if (it == s.begin()) {
            ans[ptr] = room_cnt++;
        }
        else {
            --it;
            ans[ptr] = ans[it->second];
            s.erase(it);
        }
        s.emplace(arr[ptr].second, ptr);
    }
    cout << room_cnt << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }
    
    return 0;
}
