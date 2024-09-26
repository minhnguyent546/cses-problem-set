/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-09-19 20:58:54
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
    #ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
    #endif
    cin.exceptions(cin.failbit);
    const int MAGIC = (int) 1222;
    vector<optional<int>> grundy(MAGIC + 1);
    auto sg = [&](auto &&self, int n) -> int {
        if (grundy[n].has_value()) return grundy[n].value();
        set<int> s;
        for (int i = 1; i < (n + 1) / 2; ++i) {
            assert(n - i != i);
            int val = self(self, i) ^ self(self, n - i);
            s.emplace(val);
        }
        grundy[n] = 0; 
        while (s.find(grundy[n].value()) != s.end()) {
            ++grundy[n].value();
        }
        return grundy[n].value();
    };

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n > MAGIC) {
            cout << "first" << '\n';
            continue;
        }
        cout << (sg(sg, n) == 0 ? "second" : "first") << '\n';
    }

    return 0;
}
