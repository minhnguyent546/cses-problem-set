/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-24 21:07:28
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int max_v = *max_element(arr.begin(), arr.end());
    vector<int> f(max_v + 1);
    for (int i = 0; i < n; ++i) {
        f[arr[i]]++;
    }
    vector<long long> cnt(max_v + 1);
    for (int d = 1; d <= max_v; ++d) {
        for (int m = d; m <= max_v; m += d) {
            cnt[d] += f[m];
        }
        cnt[d] = 1LL * cnt[d] * (cnt[d] - 1) / 2;
    }
    for (int v = max_v; v >= 1; --v) {
        for (int m = v * 2; m <= max_v; m += v) {
            cnt[v] -= cnt[m];
        }
    }
    cout << cnt[1] << '\n';
    return 0;
}
 
/**
cnt[g] = the number of pairs that have gcd(a, b) = g
answer = cnt[1] 
 
d[g] = number of multiples of g
*/
