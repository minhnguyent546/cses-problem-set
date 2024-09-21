/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 22:33:32
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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        --arr[i];
        pos[arr[i]] = i;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && pos[i + 1] < pos[i]) ++ans;
    }
    for (int w = 0; w < q; ++w) {
        int i, j;
        cin >> i >> j;
        --i; --j;
        if (arr[i] > arr[j]) swap(i, j);
        if (i == j) {
            cout << ans << '\n';
            continue;
        }
        if (arr[i] - 1 >= 0) {
            int p = pos[arr[i] - 1];
            if (i > p && j < p) ++ans;
            else if (i < p && j > p) --ans;
        }
        if (arr[j] + 1 < n) {
            int p = pos[arr[j] + 1];
            if (j > p && i < p) --ans;
            else if (j < p && i > p) ++ans;
        }
        if (arr[i] + 1 == arr[j]) {
            ans += (i < j ? 1 : -1);
        }   
        else {
            assert(arr[i] + 1 < n);
            int p = pos[arr[i] + 1];
            if (i > p && j < p) --ans;
            else if (i < p && j > p) ++ans;

            assert(arr[j] - 1 >= 0);
            p = pos[arr[j] - 1];
            if (j > p && i < p) ++ans;
            else if (j < p && i > p) --ans;
        }

        swap(pos[arr[i]], pos[arr[j]]);
        swap(arr[i], arr[j]);
        cout << ans << '\n';
    }
    
    return 0;
}
