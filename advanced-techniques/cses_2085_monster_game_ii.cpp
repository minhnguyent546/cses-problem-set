/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-12 02:19:47
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
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
 
struct Line {
    long long a, b;
    Line(long long _a = 0, long long _b = INF_LL): a(_a), b(_b) {}
    long long operator()(long long x) {
        return a * x + b;
    }
};
 
struct LiChao {
    int n;
    vector<Line> tree;
    LiChao() {}
    LiChao(int _n): n(_n) {
        int p = 1;
        while (p < n) p *= 2;
        tree.resize(p * 2);
    }
    void add(int x, int l, int r, Line line) {
        if (l == r) {
            if (line(l) < tree[x](l)) {
                tree[x] = line;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        bool b_mid = line(mid) < tree[x](mid);
        bool b_left = line(l) < tree[x](l);
        if (b_mid) {
            swap(tree[x], line);
        } 
        if (b_left != b_mid) {
            add(x * 2, l, mid, line);
        } else {
            add(x * 2 + 1, mid + 1, r, line);
        }
    }
    void add(Line line) {
        add(1, 0, n - 1, line);
    }
    long long query(int x, int l, int r, long long at) {
        if (l == r) {
            return tree[x](at);
        }
        int mid = l + (r - l) / 2;
        long long res = tree[x](at);
        if (at <= mid) {
            res = min(res, query(x * 2, l, mid, at));
        } else {
            res = min(res, query(x * 2 + 1, mid + 1, r, at));
        }
        return res;
    }
    long long query(long long at) {
        return query(1, 0, n - 1, at);
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
 
    int max_s = *max_element(s.begin(), s.end());
    LiChao tree(max_s + 1);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        Line new_line(f[i - 1], res);
        tree.add(Line(f[i - 1], res));
 
        res = tree.query(s[i]);
    }
    cout << res << '\n';
    return 0;
}
