/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-10-03 01:53:51
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
    string s;
    cin >> s;
    int n = s.size();
    const int ALPHABET = 26;
    const char min_char = 'A';
    vector<int> cnt(ALPHABET);
    for (char ch : s) {
        ++cnt[ch - min_char];
    }
    string ans = "";
    for (int i = 0; i < n; ++i) {
        int required = -1;
        int rem = n - i - 1;
        for (int ch = 0; ch < ALPHABET; ++ch) {
            if (cnt[ch] == 0) continue;
            if (i > 0 && ans[i - 1] - min_char == ch) continue;
            if (cnt[ch] > (rem + 1) / 2) {
                if (required != -1) {
                    cout << -1 << '\n';
                    return 0;
                }
                required = ch;
            }
        }
        if (required == -1) {
            bool found = false;
            for (int ch = 0; ch < ALPHABET; ++ch) {
                if (cnt[ch] == 0) continue;
                if (i > 0 && ans[i - 1] - min_char == ch) continue;
                ans += (char) (ch + min_char);
                --cnt[ch];
                found = true;
                break;
            }
            if (!found) {
                cout << -1 << '\n';
                return 0;
            }
        } else {
            ans += (char) (required + min_char);
            --cnt[required];
        }
    }
    cout << ans << '\n';
    
    
    return 0;
}
