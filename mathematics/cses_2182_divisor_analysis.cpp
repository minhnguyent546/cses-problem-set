/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 16:53:32
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
const int NMOD = MOD - 1;
const int INF = 0x3f3f3f3f;

int calc_number(vector<pair<int, int>> factors) {
    int res = 1;
    for (auto [p, k] : factors) {
        res = 1LL * res * (k + 1) % MOD;
    }
    return res;
}

int powmod(long long a, long long n) {
    int res = 1;
    a %= MOD;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}   

int f(int a, int k) {
    // calculate a^0 + a^1 + ... + a^k
    if (k == 0) return 1;
    int res = f(a, (k - 1) / 2);
    int b = powmod(a, (k - 1) / 2 + 1);
    res = 1LL * res * (b + 1) % MOD;
    if (k % 2 == 0) {
        res = (res + powmod(a, k));
        if (res >= MOD) res -= MOD;
    }
    return res;
}

int calc_sum(vector<pair<int, int>> factors) {
    int res = 1;
    for (auto [p, k] : factors) {
        res = 1LL * res * f(p, k) % MOD;
    }
    return res;
}

int calc_prod(vector<pair<int, int>> factors) {
    int n = (int) factors.size();
    vector<int> pref(n + 1), suf(n + 2);
    pref[0] = 1;
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = 1LL * pref[i] * (factors[i].second + 1) % NMOD;
    }
    suf[n + 1] = 1;
    for (int i = n; i > 0; --i) {
        suf[i] = 1LL * suf[i + 1] * (factors[i - 1].second + 1) % NMOD;
    }
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        auto [p, k] = factors[i - 1];
        int expo = 1LL * k * (k + 1) / 2 % NMOD * pref[i - 1] % NMOD * suf[i + 1] % NMOD;
        res = 1LL * res * powmod(p, expo) % MOD;
    }
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> factors(n);
    for (int i = 0; i < n; ++i) {
        cin >> factors[i].first >> factors[i].second;
    }

    cout << calc_number(factors) << ' ';
    cout << calc_sum(factors) << ' ';
    cout << calc_prod(factors) << '\n';
    
    return 0;
}
