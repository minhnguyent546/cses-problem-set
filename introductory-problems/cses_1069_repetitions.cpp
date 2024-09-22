/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 14:17:58
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
    string s;
    cin >> s;
    int n = (int) s.length();
    int res = 1;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i]) ++j;
        res = max(res, j - i + 1);
        i = j;
    }
    cout << res << '\n';
    
    return 0;
}
