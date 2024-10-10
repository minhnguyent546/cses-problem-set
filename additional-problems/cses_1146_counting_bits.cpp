/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-15 01:17:45
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int MAX_BIT = 100;
long long sum[MAX_BIT][2], cnt[MAX_BIT][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long num;
    cin >> num;

    string n = bitset<MAX_BIT>(num).to_string();
    int ptr = 0;
    while (ptr < (int) n.size() && n[ptr] == '0') ++ptr;
    n = n.substr(ptr);
    int sz = (int) n.size();
    cnt[sz][0] = cnt[sz][1] = 1;
    sum[sz][0] = sum[sz][1] = 0;
    for (int i = sz - 1; i >= 0; --i) {
        int ch = n[i] - '0';
        if (ch == 0) {
            // place 0
            cnt[i][1] = cnt[i + 1][1];
            sum[i][1] = sum[i + 1][1];
        } else {
            // place 0 or 1
            cnt[i][1] = cnt[i + 1][1] + cnt[i + 1][0];
            sum[i][1] = cnt[i + 1][1] + sum[i + 1][1] + sum[i + 1][0];
        }
        cnt[i][0] = cnt[i + 1][0] * 2;
        sum[i][0] = cnt[i + 1][0] + sum[i + 1][0] + sum[i + 1][0];
    }
    cout << sum[0][1] << '\n';
    return 0;
}
