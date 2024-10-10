/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-10-03 01:18:20
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

struct Info {
    array<int, 2> pref, suf;
    int best, sz;
    Info(): best(0), sz(0) {
        pref[0] = suf[0] = pref[1] = suf[1] = 0;
    }
    Info(int bit): best(1), sz(1) {
        pref[bit] = suf[bit] = 1;
        pref[bit ^ 1] = suf[bit ^ 1] = 0;
    }
    friend Info operator+(const Info &lhs, const Info &rhs) {
        Info ret;
        ret.sz = lhs.sz + rhs.sz;
        for (int bit : {0, 1}) {
            ret.pref[bit] = lhs.pref[bit] + (lhs.pref[bit] == lhs.sz ? rhs.pref[bit] : 0);
            ret.suf[bit] = rhs.suf[bit] + (rhs.suf[bit] == rhs.sz ? lhs.suf[bit] : 0);
        }
        ret.best = max({lhs.best, rhs.best, lhs.suf[0] + rhs.pref[0], lhs.suf[1] + rhs.pref[1]});
        return ret;
    }
};

struct Segtree {
    int n;
    vector<Info> tree;
    Segtree() {}
    Segtree(int _n): n(_n), tree(n * 2) {}
    Segtree(const string &s): n(s.size()), tree(n * 2) {
        for (int i = 0; i < n; ++i) {
            tree[i + n] = Info(s[i] - '0');
        }
        for (int i = n - 1; i > 0; --i) pull(i);
    }   
    void pull(int x) { tree[x] = tree[x * 2] + tree[x * 2 + 1]; }
    void set(int i, int bit) {
        tree[i += n] = Info(bit);
        for (i /= 2; i > 0; i /= 2) {
            pull(i);
        }
    }
    Info query(int l, int r) {
        Info left_ret{}, right_ret{};
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) left_ret = left_ret + tree[l++];
            if (r & 1) right_ret = tree[--r] + right_ret;
        }
        return left_ret + right_ret;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    string s;
    cin >> s;
    int n = s.size();
    Segtree tree(s);
    int q;
    cin >> q;
    for (int w = 0; w < q; ++w) {
        int pos;
        cin >> pos;
        --pos;
        s[pos] = s[pos] ^ '1' ^ '0';
        tree.set(pos, s[pos] - '0');
        cout << tree.query(0, n - 1).best << ' ';
    }
    cout << '\n';
    
    return 0;
}
