/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 21:56:33
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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map<int, int> cnt;
    int distinct = 0;
    long long ans = 0;
    for (int i = 0, j = -1; i < n; ++i) {
        while (j + 1 < n && (distinct < k || (distinct == k && cnt.find(arr[j + 1]) != cnt.end() && cnt[arr[j + 1]] > 0))) {
            ++j;
            cnt[arr[j]]++;
            if (cnt[arr[j]] == 1) ++distinct;
            cerr << i << ' ' << j << '\n';
        }
        cerr << "i = " << i << ", j = " << j << '\n';
        ans += j - i + 1;
        if (cnt[arr[i]] == 1) --distinct;
        cnt[arr[i]]--;
    }
    cout << ans << '\n';
    return 0;
}
