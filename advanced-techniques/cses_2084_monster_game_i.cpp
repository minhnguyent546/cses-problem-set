/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-12 01:09:05
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

struct Line {
    long long a, b;
    Line() {}
    Line(long long _a, long long _b): a(_a), b(_b) {}
    long long get(long long x) {
        return a * x + b;
    }
    friend ostream& operator<<(ostream &os, const Line &line) {
        return os << "(" << line.a << ", " << line.b << ")";
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> s(n + 1), f(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> s[i + 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i + 1];
    }
    f[0] = x;

    vector<Line> lines;
    int sz = 0;

    auto intersect = [&](Line me, Line other) -> pair<long long, long long> {
        return {other.b - me.b, me.a - other.a};
    };

    auto can_remove_last = [&](const Line &new_line) -> bool {
        auto x = intersect(lines[sz - 2], new_line);
        auto y = intersect(lines[sz - 2], lines[sz - 1]);
        return x.first * y.second <= x.second * y.first;
    };

    long long res = 0;
    for (int i = 1, ptr = 0; i <= n; ++i) {
        Line new_line(f[i - 1], res);
        while (sz >= ptr + 2 && can_remove_last(new_line)) {
            lines.pop_back();
            --sz;
        }
        lines.emplace_back(new_line);
        sz += 1;

        while (ptr + 1 < sz && lines[ptr].get(s[i]) > lines[ptr + 1].get(s[i])) ++ptr;
        res = lines[ptr].get(s[i]);
    }
    cout << res << '\n';
    return 0;
}
