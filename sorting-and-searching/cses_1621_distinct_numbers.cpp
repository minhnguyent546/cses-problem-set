/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 16:38:21
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
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        s.insert(value);
    }
    cout << s.size() << '\n'; 
    
    return 0;
}
