/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-09-28 15:27:21
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        int x = 0;
        for (int i = 1; i < n; i += 2) {
            x ^= p[i];
        }
        cout << (x == 0 ? "second" : "first") << '\n';
    }
    
    return 0;
}

/*
- All even indices are useless (0-indexed) as the game state doesn't change 
when the player A move some balls from an even index i to i - 1 and the player
B move those balls from i - 1 to i - 2.
- Moving some balls from an odd index i to an even index i - 1 is just like 
throwing them away (a standard nim game).
*/
