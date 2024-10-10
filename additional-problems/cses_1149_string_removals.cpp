/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-10-03 00:59:07
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int ALPHABET = 26;
const char min_char = 'a';
const int MOD = (int) 1e9 + 7;

void norm(int &x) {
    if (x < 0) x += MOD;
    else if (x >= MOD) x -= MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> latest(ALPHABET, -1);
    
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1];
        norm(dp[i]);

        int j = latest[s[i - 1] - min_char];
        if (j > 0) {
            dp[i] -= dp[j - 1];
            norm(dp[i]);
        }
        latest[s[i - 1] - min_char] = i;
    }
    int ans = dp[n] - 1;
    norm(ans);
    cout << ans << '\n';
    return 0;
}
