/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 16:40:57
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n), apartments(m);
    for (int i = 0; i < n; ++i) {
        cin >> applicants[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int cnt = 0;
    for (int i = 0, ptr = 0; i < n; ++i) {
        while (ptr < m && apartments[ptr] < applicants[i] - k) ++ptr;
        if (ptr < m && apartments[ptr] <= applicants[i] + k) {
            ++ptr;
            ++cnt;
        }
    }
    cout << cnt << '\n';
        
    return 0;
}
