/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-08-16 10:50:06
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int x = 0;
        for (int i = 0; i < n; ++i) x ^= arr[i];
        cout << (x > 0 ? "first" : "second") << '\n';
    }
    
    return 0;
}
