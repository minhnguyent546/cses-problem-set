/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:51:41
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
const long long INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long s = accumulate(arr.begin(), arr.end(), 0LL);
    long long best = INF;
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long cur_s = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                cur_s += arr[i];
            }
        }
        best = min(best, abs(s - 2 * cur_s));
    }
    cout << best << '\n';
    return 0;
}
