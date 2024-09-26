/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-24 22:58:12
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<int> known(6);
    known[0] = 1;
    for (int i = 1; i < 6; ++i) {
        for (int j = 1; j <= 6 && j <= i; ++j) {
            known[i] += known[i - j];
        }
    }
    if (n <= 5) {
        cout << known[n] << '\n';
        return 0;
    }
    using Mat = vector<vector<int>>;
    auto mult = [&](Mat a, Mat b) -> Mat {
        int na = (int) a.size(), ma = (int) a[0].size();
        int nb = (int) b.size(), mb = (int) b[0].size();
        assert (ma == nb);
        Mat ans(na, vector<int>(mb));
        for (int r = 0; r < na; ++r) {
            for (int c = 0; c < mb; ++c) {
                for (int g = 0; g < ma; ++g) {
                    ans[r][c] = (ans[r][c] + 1LL * a[r][g] * b[g][c]) % MOD;
                }
            }
        }
        return ans;
    };
    auto powmod = [&](Mat a, long long exp) -> Mat {
        int n = (int) a.size(), m = (int) a[0].size();
        assert(n == m);
        Mat res(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            res[i][i] = 1;
        }
        while (exp > 0) {
            if (exp & 1) res = mult(res, a);
            a = mult(a, a);
            exp >>= 1;
        }
        return res;
    };
    Mat M = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
    };
    Mat MM = powmod(M, n - 5);
    int ans = 0;
    for (int i = 0; i < 6; ++i) {
        ans = (ans + 1LL * MM[0][i] * known[5 - i]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
