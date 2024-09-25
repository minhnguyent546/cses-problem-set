/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-29 20:59:12
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
 
const int B = 750;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int nb = (n + B - 1) / B;
    vector<long long> sum(nb);
    for (int i = 0; i < n; ++i) {
        sum[i / B] += arr[i];
    }
    for (int w = 0; w < q; ++w) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            sum[pos / B] += val - arr[pos];
            arr[pos] = val;
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int left_block = l / B, right_block = r / B;
            long long ans = 0;
            if (left_block == right_block) {
                for (int i = l; i <= r; ++i) ans += arr[i];
            }
            else {
                for (int i = l; i < (left_block + 1) * B; ++i) ans += arr[i];
                for (int i = left_block + 1; i < right_block; ++i) ans += sum[i];
                for (int i = right_block * B; i <= r; ++i) ans += arr[i];
            }
            cout << ans << '\n'; 
        }
        else assert(false);
    }
 
    
    return 0;
}
