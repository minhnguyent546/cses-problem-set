/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 18:00:05
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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;
        --t;
        arr.emplace_back(s, t);
    }
    multiset<pair<int, int>> s;
    sort(arr.begin(), arr.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.second < rhs.second;
    });
    multiset<int> members;
    for (int i = 0; i < k; ++i) members.insert(0);
    int movie_cnt = 0;
    for (int i = 0; i < n; ++i) {
        auto it = members.lower_bound(arr[i].first);
        if (it == members.begin()) continue;
        --it;
        members.erase(it);
        members.insert(arr[i].second);
        movie_cnt++;
    }   
    cout << movie_cnt << '\n';
    return 0;
}
