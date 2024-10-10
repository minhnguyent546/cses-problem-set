/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-10-07 21:23:14
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

const int FIXED_RANDOM = 11223344 + 42;
mt19937 rng(FIXED_RANDOM);
template<typename T>
T next(T a, T b = 1) {
    if (a > b) swap(a, b);
    return uniform_int_distribution<T>(a, b)(rng);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(ALPHABET);
    int distinct = 0;
    for (char ch : s) {
        ++freq[ch - min_char];
        if (freq[ch - min_char] == 1) ++distinct;
    }
    fill(freq.begin(), freq.end(), 0);

    vector<long long> vals(ALPHABET);
    for (int i = 0; i < ALPHABET; ++i) {
        vals[i] = next(1, (int) 1e12);
    }

    int cur_distinct = 0;
    long long cur_hash = 0;
    map<long long, int> cache;
    cache[0]++;

    long long ret = 0;
    for (int i = 0; i < n; ++i) {
        ++freq[s[i] - min_char];
        cur_hash += vals[s[i] - min_char];

        if (freq[s[i] - min_char] == 1) ++cur_distinct;
        if (cur_distinct == distinct) {
            for (int ch = 0; ch < ALPHABET; ++ch) {
                if (freq[ch] > 0) {
                    cur_hash -= vals[ch];
                    --freq[ch];
                    if (freq[ch] == 0) --cur_distinct;
                }
            }
        }
        ret += cache[cur_hash];
        ++cache[cur_hash];
    }
    cout << ret << '\n';
    
    
    return 0;
}
