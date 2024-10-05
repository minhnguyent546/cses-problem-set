/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-08-10 19:11:43
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    auto make_subset = [&](int l, int r) {
        int sz = r - l + 1;
        int m = (1 << sz);
        vector<long long> res(m);
        for (int mask = 0; mask < m; ++mask) {
            long long sum = 0;
            for (int i = 0; i < sz; ++i) {
                if ((mask >> i) & 1) {
                    sum += arr[i + l];
                }
            }
            res[mask] = sum;
        }
        return res;
    };
    auto A = make_subset(0, (n - 1) / 2);
    auto B = make_subset((n + 1) / 2, n - 1);
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end());
    long long ans = 0;
    for (int i = 0, ptr = 0, nptr = 0; i < (int) A.size(); ++i) {
        long long target = x - A[i];
        while (ptr < (int) B.size() && B[ptr] < target) ++ptr;
        while (nptr < (int) B.size() && B[nptr] <= target) ++nptr;
        if (ptr < (int) B.size() && B[ptr] == target) {
            ans += nptr - ptr;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
