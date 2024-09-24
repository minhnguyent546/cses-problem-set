/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-09-24 20:02:09
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int ALPHABET = 10;
const char min_char = '0';
const long long UNSET = -1;
long long dp[20][2][ALPHABET][2];
long long work(const string &s, int i, bool tight, int prev_digit, bool non_zero) {
    if (i == (int) s.size()) return 1;

    auto& ret = dp[i][tight][prev_digit][non_zero];
    if (ret != UNSET) return ret;

    int max_digit = (tight ? s[i] - min_char : ALPHABET - 1);
    ret = 0;
    for (int d = 0; d <= max_digit; ++d) {
        if (!non_zero || d != prev_digit) {
            ret += work(s, i + 1, tight && d == max_digit, d, non_zero || d != 0);
        }    
    }
    return ret;
}

long long solve(long long n) {
    memset(dp, -1, sizeof(dp));
    return work(to_string(n), 0, true, -1, false);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    long long a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << '\n';
    
    return 0;
}
