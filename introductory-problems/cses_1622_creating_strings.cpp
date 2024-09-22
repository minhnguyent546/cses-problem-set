/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:48:41
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
    sort(s.begin(), s.end());
    vector<string> perms;
    do {
        perms.emplace_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << perms.size() << '\n';
    for (const string &s : perms) {
        cout << s << '\n';
    }
    return 0;
}
