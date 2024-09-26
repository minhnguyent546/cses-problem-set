/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-08-16 11:17:49
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
    // int n;
    // cin >> n;
    // vector<int> grundy(n + 1);
    // grundy[0] = 0;
    // for (int i = 1; i <= n; ++i) {
    //     set<int> s;
    //     for (int j = 1; j <= 3 && j <= i; ++j) {
    //         s.insert(grundy[i - j]);
    //     }
    //     for (int ptr = 0; ; ++ptr) {
    //         if (s.find(ptr) == s.end()) {
    //             grundy[i] = ptr;
    //             break;
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; ++i) {
    //     cerr << i << ' ' << grundy[i] << '\n';
    // }
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
        for (int i = 0; i < n; ++i) {
            int g = (arr[i] % 4);
            x ^= g;
        }
        cout << (x > 0 ? "first" : "second") << '\n';
    }
    return 0;
}
