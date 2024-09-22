/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-15 15:12:19
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
    const int ALPHABET = 26;
    const char MIN_CHAR = 'A';
    vector<int> cnt(ALPHABET);
    for (char ch : s) {
        cnt[ch - MIN_CHAR]++;
    }
    int odd_idx = -1;
    for (int i = 0; i < ALPHABET; ++i) {
        if (cnt[i] & 1) {
            if (odd_idx != -1) {
                cout << "NO SOLUTION" << '\n';
                return 0;
            }
            odd_idx = i;
        }
    }
    string res = "";
    for (int i = 0; i < ALPHABET; ++i) {
        res += string(cnt[i] / 2, (char) (i + MIN_CHAR));
    }
    string rev = res;
    reverse(rev.begin(), rev.end());
    if (odd_idx != -1) {
        cout << res + (char) (odd_idx + MIN_CHAR) + rev << '\n';
    }
    else {
        cout << res + rev << '\n';
    }
    return 0;
}
