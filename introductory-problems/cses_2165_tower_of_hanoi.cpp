/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:45:44
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
    int a = 1;
    int b = 2;
    int c = 3;
    int n;
    cin >> n;
    auto work = [&](auto &&self, int n, int a, int c, int b) -> void {
        if (n == 0) return;
        self(self, n - 1, a, b, c);
        cout << a << ' ' << c << '\n';
        self(self, n - 1, b, c, a);
    };
    cout << (1 << n) - 1 << '\n';
    work(work, n, a, c, b);

    
    return 0;
}
