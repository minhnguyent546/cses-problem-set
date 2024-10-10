/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-09-30 23:40:39
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
    const string chars = "ACGT";
    int n = (int) s.size();
    vector<array<int, 4>> next(n + 1);
    next[n].fill(n);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i] == chars[j]) next[i][j] = i;
            else next[i][j] = next[i + 1][j];
        }
    }
    const int INF = 0x3f3f3f3f;
    vector<int> dp(n + 1, INF);
    vector<int> trace(n + 1, -1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (next[i][j] == n) {
                dp[i] = 1;
                trace[i] = j;
            }
            else if (dp[i] > dp[next[i][j] + 1] + 1) {
                dp[i] = dp[next[i][j] + 1] + 1;
                trace[i] = j;
            }
        }
    }
    cerr << dp[0] << '\n';
    string ans = "";
    int cur = 0;
    while (cur < n) {
        int j = trace[cur];
        assert(j != -1);
        ans += chars[j];
        cur = next[cur][j] + 1;
    }
    cout << ans << '\n';
    
    return 0;
}

/*
- let dp[i] = length of the shortest sequence (T) that is not a subsequence of S
- Assume T = c????? (c is an arbitrary character), next[c][i] = smallest j >= i s.t. S[j] = c
    + c is not appear in S[i:] (or next[c][i] = n) => dp[i] = 1
    + otherwise, dp[i] = dp[next[c][i] + 1] + 1
- related problem: https://atcoder.jp/contests/arc081/tasks/arc081_c
*/
