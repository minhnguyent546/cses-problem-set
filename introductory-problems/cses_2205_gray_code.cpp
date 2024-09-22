/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:19:44
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
    using Bit = bitset<16>;
    vector<int> values = {0, 1};
    for (int i = 1; i < n; ++i) {
        for (int &v : values) {
            v *= 2;
        }
        for (int j = (int) values.size() - 1; j >= 0; --j) {
            values.emplace_back(values[j] + 1);
        }
        cerr << values.size() << '\n';
    }
    for (int value : values) {
        cout << Bit(value).to_string().substr(16 - n) << '\n';
    }
    
    return 0;
}
