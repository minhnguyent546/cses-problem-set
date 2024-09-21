/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 11:48:51
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
    int ans = 0;
    long long s = 0;
    for (int i = 0, j = -1; i < n; ++i) {
        while (j + 1 < n && s < x) {
            s += arr[j + 1];
            ++j;
        }
        if (s == x) ++ans;
        s -= arr[i];
    }   
    cout << ans << '\n';
    
    return 0;
}
